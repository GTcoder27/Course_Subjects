from langgraph.graph import START,END,StateGraph
from typing import TypedDict,Annotated
from langchain_core.messages import BaseMessage,HumanMessage,AIMessage,SystemMessage
from langchain_ollama import ChatOllama
from langgraph.graph.message import add_messages
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.checkpoint.sqlite import SqliteSaver
import sqlite3
from langchain.tools import tool
from langchain_community.tools.ddg_search.tool import DuckDuckGoSearchRun
from langgraph.prebuilt.tool_node import ToolNode,tools_condition
# from dotenv import load_dotenv
# load_dotenv()


llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)




########## tools ##########
@tool
def web_search_tool(query:str):
    """This tool is used for searching the web to fetch latest events,news or any other things"""
    duck_duck_go_search = DuckDuckGoSearchRun()
    res = duck_duck_go_search.invoke(query) 
    return res

tools = [web_search_tool]
llm_with_tools = llm.bind_tools(tools)



class ChatState(TypedDict):
    messages: Annotated[list[BaseMessage],add_messages]


########## nodes ##########
def chat_node(state:ChatState):
    """LLM node that will answer or request a tool call."""
    messages = state['messages']
    res = llm_with_tools.invoke(messages)
    return {'messages':[res]}

tools_node = ToolNode(tools)


########## Graph #############
conn = sqlite3.connect(database='sqlite_store/chatbot_chats.db',check_same_thread=False)
checkpointer = SqliteSaver(conn=conn)

graph = StateGraph(ChatState)
graph.add_node('chat_node',chat_node)
graph.add_node('tools',tools_node)

graph.add_edge(START,'chat_node')
graph.add_conditional_edges('chat_node',tools_condition)
graph.add_edge('tools','chat_node')

chatbot = graph.compile(checkpointer=checkpointer) 






####### Other functions ########
def retrive_all_threads():
    all_threads = set()
    for checkpoint in checkpointer.list(None):
        all_threads.add(checkpoint.config['configurable']['thread_id'])
    return list(all_threads)



