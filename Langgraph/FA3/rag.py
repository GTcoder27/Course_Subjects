from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_community.document_loaders import PyPDFLoader,TextLoader
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_community.vectorstores import Chroma,FAISS
from langchain_classic.chains.combine_documents import create_stuff_documents_chain
from langchain_classic.chains.retrieval import create_retrieval_chain
from langchain_core.prompts import ChatPromptTemplate
from langchain_community.retrievers import BM25Retriever
from langchain_classic.retrievers import EnsembleRetriever




llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)
embedding_model = OllamaEmbeddings(model="nomic-embed-text")



loader = PyPDFLoader("data/sample_invoice.pdf")
documents = loader.load()

text_splitter = RecursiveCharacterTextSplitter(
    chunk_size=100,
    chunk_overlap=20,
    separators=['\n\n','\n',' ', '']
)
chunks = text_splitter.split_documents(documents)


db = Chroma.from_documents(
    documents=chunks,
    embedding=embedding_model
)

system_prompt = ChatPromptTemplate.from_messages([
    ('system',"give answer only based on below given context: {context}"),
    ('human',"{input}")
])

retriever = db.as_retriever(search_type="similarity",search_kwargs={'k':3})
combine_docs_chain = create_stuff_documents_chain(llm=llm,prompt=system_prompt,document_variable_name='context')
retrieval_chain = create_retrieval_chain(retriever=retriever,combine_docs_chain=combine_docs_chain)

res = retrieval_chain.invoke({'input':"what is total amount"})


print(res['answer'])






