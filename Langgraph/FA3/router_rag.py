from langgraph.store.memory import InMemoryStore
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.graph import StateGraph,START,END
import getpass 
import os
from langchain_core.prompts import ChatPromptTemplate
from langchain_community.vectorstores import Chroma,FAISS
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_community.document_loaders import PyPDFLoader
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_aws import ChatBedrockConverse,BedrockEmbeddings
from langgraph.prebuilt import tools_condition,ToolNode
from langchain_core.tools import tool
from langchain_tavily import TavilySearch
from dotenv import load_dotenv
from typing import TypedDict,Any,Annotated
load_dotenv()



if not os.environ.get('TAVILY_API_KEY',''):
    os.environ['TAVILY_API_KEY'] = getpass.getpass("Tavily api key")

llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)
embedding_model = OllamaEmbeddings(model="nomic-embed-text")
tavily = TavilySearch(
    max_results=1,
    topic="general",
    search_depth="basic",
    include_answer="advanced",
    include_raw_content="text",
    include_images=False,
    include_image_descriptions=False,
    include_domains=['arxiv.org'],
    exclude_domains=['medium.com']
)

document = PyPDFLoader("./data/sample_invoice.pdf").load()
chunks = RecursiveCharacterTextSplitter(
    chunk_size=100,
    chunk_overlap=20,
    separators=['\n\n','\n',' ','']
).split_documents(documents=document)
db = Chroma.from_documents(
    documents=chunks,
    embedding=embedding_model
)
retriever = db.as_retriever(search_type='mmr',search_kwargs={'k':2})


class RouterState(TypedDict):
    query: str
    retrieved_docs: list[str]
    answer: str

def router_node(state:RouterState):
    return state

def route_decision(state:RouterState):
    query = state['query']
    if any(word in query.lower() for word in ['latest','current','recent','today']):
        return 'web'
    else:
        return 'vdb'

def vdb_node(state:RouterState):
    res = retriever.invoke(state['query'])
    docs = [r.page_content for r in res]
    return {'retrieved_docs':docs}

def web_node(state:RouterState):
    res = tavily.invoke(state['query'])
    docs = [doc['content'] for doc in res['results']]
    return {'retrieved_docs':docs}

def generation_node(state:RouterState):
    context = '\n'.join(doc for doc in state['retrieved_docs'])
    prompt = f"""Give the answer only based on the given provided context.\n Context: {context} \n
        Question : {state['query']}"""
    res = llm.invoke(prompt)
    return {'answer':res.content}

builder = StateGraph(RouterState)
builder.add_node('vdb_node',vdb_node)
builder.add_node('web_node',web_node)
builder.add_node('generator_node',generation_node)
builder.add_conditional_edges(
    START,
    route_decision,
    {
        'web':'web_node',
        'vdb':'vdb_node'
    }
)
builder.add_edge('web_node','generator_node')
builder.add_edge('vdb_node','generator_node')
builder.add_edge('generator_node',END)

app = builder.compile(checkpointer=InMemorySaver())

print(app.get_graph().draw_ascii())

config = {'configurable':{'thread_id':'thread1'}}
res = app.invoke({'query':'recent news incident on actor tigor shrof'},config=config)

print(res['answer'])



