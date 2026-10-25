from langchain_community.vectorstores import Chroma,FAISS
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_core.documents import Document


llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)
embeddings = OllamaEmbeddings(model='nomic-embed-text')


doc1 = Document(
    page_content="Cricket is a bat-and-ball sport played between two teams of 11 players. The main objective is to score more runs than the opposing team.",
    metadata={"topic": "cricket basics"}
)

doc2 = Document(
    page_content="Cricket is played in formats such as Test, ODI, and T20. Test matches can last up to five days, while ODIs have 50 overs and T20 matches have 20 overs per team.",
    metadata={"topic": "cricket formats"}
)

doc3 = Document(
    page_content="Batting involves scoring runs while protecting the wicket. Common cricket shots include the cover drive, straight drive, pull, hook, cut, and sweep.",
    metadata={"topic": "cricket batting"}
)

doc4 = Document(
    page_content="Bowling is used to take wickets and restrict the batting team from scoring runs. Fast bowlers use pace and swing, while spin bowlers use variations and turn.",
    metadata={"topic": "cricket bowling"}
)

doc5 = Document(
    page_content="Fielding helps prevent runs and create opportunities for dismissals. Captains change field positions and bowling strategies based on the batter and match situation.",
    metadata={"topic": "cricket fielding"}
)

docs = [doc1,doc2,doc3,doc4,doc5]


vector_store = Chroma(
    embedding_function=embeddings,
    persist_directory='my_chroma_db',
    collection_name='sample'
)

vector_store.add_documents(docs)

# vector_store.get(include=['embeddings','documents','metadatas'])

retriver = vector_store.as_retriever(search_kwargs={"k":2})
# retriver = vector_store.as_retriever(search_type='similarity',search_kwargs={"k":2}) # above and this are same

res = retriver.invoke("what is the cricket bowling")
print(res)











