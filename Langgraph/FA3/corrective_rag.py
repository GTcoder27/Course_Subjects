from langgraph.graph import StateGraph,START,END
from typing import Any,TypedDict,Annotated
from langchain_core.documents import Document
import os 
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_classic.document_loaders import PyPDFLoader
from langchain_community.vectorstores import Chroma,FAISS
from langchain_core.prompts import ChatPromptTemplate
from pydantic import BaseModel,Field
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langgraph.checkpoint.memory import InMemorySaver
from langchain_core.output_parsers import StrOutputParser
from langchain_tavily import TavilySearch
from langchain_community.tools.tavily_search import TavilySearchResults
from dotenv import load_dotenv
import getpass
load_dotenv()



if not os.environ.get('TAVILY_API_KEY',''):
    os.environ['TAVILY_API_KEY'] = getpass.getpass("Tavily api key")

llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)
embedding_model = OllamaEmbeddings(model="nomic-embed-text")
tavily = TavilySearch(
    max_results=1,
    topic="general",
    search_depth="advanced",
    include_answer="advanced",
    include_raw_content="text",
    # include_images=False,
    # include_image_descriptions=False,
    # include_domains=['arxiv.org'],
    # exclude_domains=['medium.com']
)

document = PyPDFLoader('./data/sample_invoice.pdf').load()
chunks = RecursiveCharacterTextSplitter(
    separators=['\n\n','\n',' ',''],
    chunk_size=100,
    chunk_overlap=20
).split_documents(documents=document)


FAISS_PATH = './data/database'

if os.path.exists(FAISS_PATH):
    research_db = FAISS.load_local(
        folder_path=FAISS_PATH,
        embeddings=embedding_model,
        allow_dangerous_deserialization=True
    )
    print("Loaded existing FAISS index")
else:
    research_db = FAISS.from_documents(
        documents=chunks,
        embedding=embedding_model
    )
    research_db.save_local(FAISS_PATH)
    print("Created and saved new FAISS Index")

retriever = research_db.as_retriever(search_type='mmr',search_kwargs={'k':2})



class GradeDocuments(BaseModel):
    """Binary score for relevance check on retrieved documents"""
    binary_score: str = Field(description="""If documents are relevant to the question then 'yes' otherwise 'no'""")

grade_prompt = ChatPromptTemplate.from_messages([
    (
        'system',
        """ You are grader assessing relevance of a retrieved document to a user question.\n 
        If the document contains keywords or semantic meaning related to the question then grade it as relevant.\n
        """
    ),
    ('human',"Retrieved Document: \n {document},\n Question : \n {question}")
])

retrieval_grader = grade_prompt | llm.with_structured_output(GradeDocuments)



rag_prompt = ChatPromptTemplate.from_messages([
    (
        'system',
        """ You are an assistant for question answering task. \n
        Use the provided context and answer the question.
        If the provided context is not enough to generate the answer then simply say 'I don't know'.\n
        Context: \n {context} 
        """
    ),
    ('human',"Question: {question}")
])

rag_chain = rag_prompt | llm | StrOutputParser()



re_writer_prompt = ChatPromptTemplate.from_messages([
    (
        'system',
        """ You are an question rewriter that converts a input question to a better version that id optimized for web search."""
    ),
    ('human',"Initial question: {question}. \n Formulate an improved question.")
])

question_rewriter = re_writer_prompt | llm | StrOutputParser()



class GraphState(TypedDict):
    question:str
    answer: str
    web_search: bool
    documents: list[str]

def retrieve(state:GraphState):
    docs = retriever.invoke(state['question'])
    return {'documents':docs}

def generate(state:GraphState):
    res = rag_chain.invoke({'context':state['documents'],'question':state['question']})
    return {'answer':res}

def grade_documents(state:GraphState):
    web_search = False
    filtered_docs = []
    for doc in state['documents']:
        res = retrieval_grader.invoke({'document':doc.page_content,'question':state['question']})
        if res.binary_score.strip() == 'yes':
            filtered_docs.append(doc)
        else: 
            web_search = True
    return {'documents':filtered_docs,'web_search':web_search}

def transform_query(state:GraphState):
    better_question = question_rewriter.invoke({'question':state['question']})
    return {'question':better_question}

def web_search(state:GraphState):
    res = tavily.invoke(state['question'])
    docs = state['documents']
    for doc in res['results']:
        docs.append(Document(page_content=doc['content']))
    return {'documents':docs}

def decide_to_generate(state:GraphState):
    if state['web_search']:
        return 'web_search'
    else:
        return 'generate'

graph = StateGraph(GraphState)
graph.add_node('retrieve_node',retrieve)
graph.add_node('generate_node',generate)
graph.add_node('grade_documents_node',grade_documents)
graph.add_node('transform_query_node',transform_query)
graph.add_node('web_search_node',web_search)

graph.add_edge(START,'retrieve_node')
graph.add_edge('retrieve_node','grade_documents_node')
graph.add_conditional_edges(
    'grade_documents_node',
    decide_to_generate,
    {
        'web_search':'transform_query_node',
        'generate':'generate_node'
    }
)
graph.add_edge('transform_query_node','web_search_node')
graph.add_edge('web_search_node','generate_node')
graph.add_edge('generate_node',END)

app = graph.compile(checkpointer=InMemorySaver())

print(app.get_graph().draw_ascii())

config = {'configurable':{'thread_id':'therad1'}}
res = app.invoke({'question':'what is the tiger shroff and lawrence bhishnoi news today.'},config=config)
# res = app.invoke({'question':'what is the total amount of invoice'},config=config)


print(res['answer'])












