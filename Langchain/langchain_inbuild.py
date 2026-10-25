from langchain_openai import ChatOpenAI
from dotenv import load_dotenv
load_dotenv()
model = ChatOpenAI(model='gpt-4',temperature=0)
result = model.invoke("what is capital of india ?")


from langchain_anthropic import ChatAnthropic
model = ChatAnthropic(model='claud-3-opus',temperature=0)
result = model.invoke("how are you ?")


from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline,HuggingFaceEndpoint
import os
os.environ['HF_HOME'] = '/run/media/gtcoder/Data/Coding/HuggingFace'
llm = HuggingFacePipeline.from_model_id(
    model_id='TinyLlama/TinyLlama-1.1B-Chat-v1.0',
    task='text-generation',
    pipeline_kwargs=dict(
        temperature=0.5,
        max_new_tokens=100
    )
)
model = ChatHuggingFace(llm=llm)
res = model.invoke("what is the capital of india ?")


from langchain_ollama import ChatOllama
model = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)


#############################################################################################


from langchain_aws import ChatBedrockConverse,BedrockEmbeddings
llm = ChatBedrockConverse(model='us.antropic.claude-haiku-4-5-20251001-v1:0',region_name='us-east-1',max_tokens=200)
embeddings = BedrockEmbeddings(model_id='amazon.titan-embed-text-v1',region_name='us-east-1')
res = embeddings.embed_query("Hi I am Girish")


from langchain_core.prompts import ChatPromptTemplate,PromptTemplate,MessagesPlaceholder
from langchain.messages import HumanMessage,AIMessage,SystemMessage
prompt = ChatPromptTemplate([
    ('system','you are a helpful assistant'),
    MessagesPlaceholder(variable_name='chat_history'),
    ('user','what is the capital of {country}?')
])
prompt = PromptTemplate(
    template='what is the capital of {country}',
    input_variables=['country']
)
formated_prompt = prompt.format({'country':'India'})


from langchain_core.documents import Document
doc = Document(
    page_content="content to be put here ",
    metadata={'source':'Infosys','writer':'GT'}
)


from langchain_classic.chains.combine_documents import create_stuff_documents_chain
prompt = PromptTemplate.from_template("summarize the content {text}")
chain = create_stuff_documents_chain(prompt=prompt , llm=llm)
res = chain.invoke({'text': doc})


from langchain_core.prompts import FewShotPromptTemplate
from langchain_core.output_parsers import StrOutputParser,PydanticOutputParser,JsonOutputParser
prompt = FewShotPromptTemplate(
    examples=examples,
    examples_prompt=example_prompt,
    prefix='answer the question with reasoning steps',
    suffix="Question :{input}",
    input_variables=['input']
)
llm = prompt | llm | StrOutputParser()
res = llm.invoke({'input':'hello'})


from collections import Counter
responses = []  # append all responses in this list 
most_common_res = Counter(responses).most_common(1)[0][0]


from langchain_community.document_loaders import PyPDFLoader,TextLoader,CSVLoader,YoutubeLoader,UnstructuredXMLLoader
loader = PyPDFLoader("data/system_design.pdf")
pdf = loader.load()
youtube_loader = YoutubeLoader.from_youtube_url("url",add_video_indo=False)
youtube_transcript = youtube_loader.load()


from langchain_text_splitters import RecursiveCharacterTextSplitter
text_splitter = RecursiveCharacterTextSplitter(
    chunk_size=200,
    chunk_overlap=50,
    seperators=['\n\n','\n','.',' ']
)
docs = text_splitter.split_documents(doc)


from langchain_community.vectorstores import FAISS,Chroma
db = FAISS.from_documents(
    docs,
    embedding=embeddings
)
db.save_local("vector_db")
db = FAISS.load_local("vector_db")
res = db.similarity_search("what is this bro",k=2)


from langchain_classic.chains.retrieval_qa.base import RetrievalQA
retriever = db.as_retriever(search_type='similarity',search_kwargs={'k':2})
qa = RetrievalQA.from_chain_type(
    llm=llm,
    chain_type='stuff',
    retriever=retriever,
    return_source_document=True
)
res = qa.invoke("what is quantum computing ?")


from langchain_classic.chains.combine_documents import create_stuff_documents_chain
prompt = PromptTemplate.from_template("summarize the content {text}")
chain = create_stuff_documents_chain(prompt=prompt , llm=llm)
from langchain_classic.chains.retrieval import create_retrieval_chain
retriever_chain = create_retrieval_chain(retriever=retriever,combine_docs_chain=chain)


from langchain.agents import create_agent
from langchain_core.tools import tool
@tool
def tool1():
    pass
tools = [tool1]
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt="you are a helpful agent"
)
prompt = {
    'messages':[
        {
            'role':'human',
            'content':'what is 10 + 4'
        }
    ]
}
res = agent.invoke(prompt)



# chian based memory
from langchain_core.runnables.history import RunnableWithMessageHistory
from langchain_core.chat_history import InMemoryChatMessageHistory
from langchain_core.messages import trim_messages,AIMessage,HumanMessage,SystemMessage
chat_history = {}
store = {}
def get_session_history(session_id:str) -> InMemoryChatMessageHistory:
    if session_id not in store:
        store[session_id] = InMemoryChatMessageHistory()
    messages = store[session_id].messages
    trimmed = trim_messages(
        messages=messages,
        token_counter=len, # can take llm
        max_messages=3,
        start_on='human',
        strategy='last',
        include_system=True,
        allow_partial=False
    )
    store[session_id].messages = trimmed # or store[session_id] = InMemoryMessageHistory(messages=trimmed)
    chat_history = store[session_id]
    return chat_history
prompt = ChatPromptTemplate.from_messages([
    ('system',"you are a helpful assistant"),
    MessagesPlaceholder(variable_name='chat_history'),
    ('human','{input}')
])
runnable = prompt | llm
chain = RunnableWithMessageHistory(
    runnable,
    get_session_history=get_session_history,
    input_messages_keys=['input'],
    history_messages_key='chat_history'
)
config = {
    'configurable':{'session_id':'session1'}
}
res = chain.invoke({'input':'Hi my name is girish'},config=config)
res = store['session1'].messages



# agent based memory
from langgraph.checkpoint.memory import InMemorySaver
@tool
def latest_news():
    """fetches any latest news events"""
    pass
tools = [latest_news]
agent = create_agent(
    model=llm,
    tools=tools,
    checkpointer=InMemorySaver(),
    system_prompt="You are a helpful agent"
)
config = {'configurable':{'thread_id':'thread1'}}
prompt = {
    'messages':[HumanMessage(content="Hi I am girish")]
}
res = agent.invoke(prompt,config=config)



# Summarization Middleware
from langchain.agents.middleware import SummarizationMiddleware
from langgraph.checkpoint.memory import InMemorySaver
from langchain_core.tools import tool
from langchain.agents import create_agent
from langchain_aws import ChatBedrockConverse
@tool
def latest_news():
    """fetches any latest news events"""
    pass
tools = [latest_news]
llm = ChatBedrockConverse(
    model_id='sonet',
    region_name='us-east-1'
)
summary_model = ChatBedrockConverse(
    model_id='sonet',
    region_name='us-east-1'
)
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt="You are a helpful agent",
    checkpointer=InMemorySaver(),
    middleware=[
        SummarizationMiddleware(
            model=summary_model,
            trigger=('tokens',400),
            keep=('messages',6)
        )
    ]
)
config = {'configurable':{'thread_id':'thread1'}}
prompt = {
    'messages':[HumanMessage(content="Hi I am girish")]
}
res = agent.invoke(prompt,config=config)





# PII Middleware
from langchain.agents.middleware import PIIMiddleware
from langgraph.checkpoint.memory import InMemorySaver
from langchain_core.tools import tool
from langchain.agents import create_agent
from langchain_aws import ChatBedrockConverse
@tool
def latest_news():
    """fetches any latest news events"""
    pass
tools = [latest_news]
llm = ChatBedrockConverse(
    model_id='sonet',
    region_name='us-east-1'
)
agent = create_agent(
    model=llm,
    tools=tools,
    system_prompt=(
        "You are a secure banking assistant."
        "sensitive data in your input has been masked for security"
        "process the user's request using the available tools."
    ),
    checkpointer=InMemorySaver(),
    middleware=[
        PIIMiddleware("email",strategy='redact',apply_to_input=True),
        PIIMiddleware("credit_card",strategy='redact',apply_to_input=True)
    ]
)
config = {'configurable':{'thread_id':'thread1'}}
prompt = {
    'messages':[HumanMessage(content="Hi I am girish my email id is g@gmail.com")]
}
res = agent.invoke(prompt,config=config)







