from langchain_community.document_loaders.youtube import YoutubeLoader
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import PromptTemplate
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_core.runnables import RunnableLambda,RunnableParallel,RunnablePassthrough
from langchain_core.output_parsers import StrOutputParser
from langchain.tools import tool , InjectedToolArg
from typing import Annotated


llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)


@tool
def multiply_function(a:int,b:int) -> int:
    """multiply two numbers"""
    return a * b
@tool
def add_function(a:int,b:int,c:Annotated[int,InjectedToolArg]) -> int:
    """add two numbers"""
    return a + b


llm_with_tools = llm.bind_tools([multiply_function,add_function])


res = llm_with_tools.invoke("add 3 and 8")
print(res.tool_calls)
print('*'*10)
res = multiply_function.invoke(res.tool_calls[0])
print(res)




















