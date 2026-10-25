from langgraph.graph import START,END,StateGraph
from typing import TypedDict,Annotated
from langchain_core.messages import BaseMessage,HumanMessage,AIMessage,SystemMessage
from langchain_ollama import ChatOllama
from langgraph.graph.message import add_messages
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.checkpoint.sqlite import SqliteSaver
import sqlite3



llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2,max_token=100)

class ChatState(TypedDict):
    messages: Annotated[list[BaseMessage],add_messages]

def chat_node(state:ChatState):
    messages = state['messages']
    res = llm.invoke(messages)
    return {'messages':[AIMessage(res.content)]}


# REQUIRED : make a folder name sqlite_store 
conn = sqlite3.connect(database='sqlite_store/chatbot_chats.db',check_same_thread=False)

checkpointer = SqliteSaver(conn=conn)

graph = StateGraph(ChatState)

graph.add_node('chat_node',chat_node)

graph.add_edge(START,'chat_node')
graph.add_edge('chat_node',END)

chatbot = graph.compile(checkpointer=checkpointer) 

# config = {'configurable': {'thread_id':'thread-2'}}
# res = chatbot.invoke({'messages':[HumanMessage(content="hi")]},config=config)
# print('AI : ',res['messages'][-1].content)

# print(chatbot.get_state(config=config).values)



def retrive_all_threads():
    all_threads = set()
    for checkpoint in checkpointer.list(None):
        all_threads.add(checkpoint.config['configurable']['thread_id'])
    return list(all_threads)



