from langchain_community.document_loaders.youtube import YoutubeLoader
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import PromptTemplate
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_ollama import ChatOllama,OllamaEmbeddings
from langchain_core.runnables import RunnableLambda,RunnableParallel,RunnablePassthrough
from langchain_core.output_parsers import StrOutputParser
from langchain.tools import tool , InjectedToolArg
from typing import Annotated
from langchain_community.tools import DuckDuckGoSearchRun
from langchain.agents import create_agent
from langchain_classic.agents.agent import AgentExecutor


llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)

web_search = DuckDuckGoSearchRun() 

@tool
def web_search_tool(query:str) -> int:
    """Search for latest news and events"""
    return web_search.invoke(query)

system_prompt = "You are a helpful assistance"

agent = create_agent(
    model=llm,
    tools=[web_search_tool],
    system_prompt=system_prompt,
)

prompt = {
    'messages': [
        {
            'role':'user',
            'content': 'tell me about the recent flood in nepal'
        }
    ]
}

res = agent.invoke(prompt)

for msg in res['messages']:
    print(msg)
    print('*'*20)













