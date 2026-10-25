from langchain_community.document_loaders.youtube import YoutubeLoader
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import PromptTemplate
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_core.runnables import RunnableLambda,RunnableParallel,RunnablePassthrough
from langchain_core.output_parsers import StrOutputParser



llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)
embeddings = OllamaEmbeddings(model='nomic-embed-text')


video_id = '9W3XpE9uGQ4'
youtube_loader = YoutubeLoader(
    video_id=video_id,
    language='en'
)
transcript = youtube_loader.load()


splitter = RecursiveCharacterTextSplitter(
    chunk_size=100,
    chunk_overlap=25
)
chunks = splitter.split_documents(transcript)
print(len(chunks))


vector_store = FAISS.from_documents(
    documents=chunks,
    embedding=embeddings
) 
retriever = vector_store.as_retriever(search_type='similarity',search_kwargs={'k':4})
# res = retriever.invoke("what is proxy for ai agents")
# print(res)


prompt = PromptTemplate(
    template="""You are a helpful assistant.
        Answer only from the provided transcript context.
        If the context is insufficient then just say don't know.
        {context}
        Question : {question}
    """,
    input_variables=['context','question']
)
question = "is the topic of alians discussed in the video? if yes then what is discussed"
question = "what is agentic ai"


# retrieved_docs = retriever.invoke(question)
# context = (doc.page_content for doc in retrieved_docs)
# print(context)
# final_prompt = prompt.invoke({'context':context,'question':question})
# res = llm.invoke(final_prompt)
# print(res.content)


def format_docs(retrieved_docs):
    return (doc.page_content for doc in retrieved_docs)

parallel_chain = RunnableParallel({
    'context': retriever | RunnableLambda(format_docs),
    'question': RunnablePassthrough()
})

chain = parallel_chain | prompt | llm | StrOutputParser()
res = chain.invoke(question)
print(res)













