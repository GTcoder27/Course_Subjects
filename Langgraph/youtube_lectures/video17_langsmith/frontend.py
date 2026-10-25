import streamlit as st
from temp_runners.backend import chatbot,retrive_all_threads
from langchain_core.messages import HumanMessage,AIMessage
import uuid
from dotenv import load_dotenv
load_dotenv()


################### Utility Functions #####################
def generate_thread_id():
    thread_id = uuid.uuid4()
    return str(thread_id)

def reset_chat():
    thread_id = generate_thread_id()
    st.session_state['thread_id'] = thread_id
    add_new_chat_thread(st.session_state['thread_id'])
    st.session_state['chat_history'] = []

def add_new_chat_thread(thread_id):
    if thread_id not in st.session_state['chat_threads']:
        st.session_state['chat_threads'].append(thread_id)

def load_conversation(thread_id):
    st.session_state['thread_id'] = thread_id
    config = {'configurable':{'thread_id':thread_id}}
    st.session_state['chat_history'] = []
    try:
        messages = chatbot.get_state(config=config).values['messages']
        for msg in messages:
            st.session_state['chat_history'].append({'role':msg.type,'content':msg.content})
    except Exception as ex:
        st.text("No messages found")
        
    





################### session setup #####################
if 'chat_history' not in st.session_state:
    st.session_state['chat_history'] = []

if 'chat_threads' not in st.session_state:
    st.session_state['chat_threads'] = retrive_all_threads()

if 'thread_id' not in st.session_state:
    st.session_state['thread_id'] = generate_thread_id() 
    add_new_chat_thread(st.session_state['thread_id'])


    



################### sidebar UI ######################
st.sidebar.title("LangGraph Chatbot")

if st.sidebar.button("New Chat"):
    reset_chat()

st.sidebar.header("My Conversations")

for thread_id in reversed(st.session_state['chat_threads']):
    if st.sidebar.button(str(thread_id)):
        load_conversation(str(thread_id))




################## Main UI ###########################
for msg in st.session_state['chat_history']:
    with st.chat_message(msg['role']):
        st.text(msg['content'])

user_input = st.chat_input("Ask ")

# config = {'configurable': {'thread_id': st.session_state['thread_id']}}

# This is for Langsmith if you want to trace every node of langgraph (otherwise you can use above config)
config = {
    'configurable': {'thread_id': st.session_state['thread_id']},
    'metadata': {'thread_id': st.session_state['thread_id']},
    'run_name': "chat_turn",  # this is not cumpulsory, this will only the name
}

if user_input:
    with st.chat_message('human'):
        st.text(user_input)
    st.session_state['chat_history'].append({'role':'human','content':user_input})

    with st.chat_message('ai'):
        response = st.write_stream(
            message_chunk.content for message_chunk,metadata in chatbot.stream(
                {'messages':[HumanMessage(content=user_input)]},
                config=config,
                stream_mode='messages')
        )
    st.session_state['chat_history'].append({'role':'ai','content':response})





