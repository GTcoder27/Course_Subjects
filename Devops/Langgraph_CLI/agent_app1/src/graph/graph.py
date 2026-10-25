from typing import TypedDict, Literal,List,Dict,Annotated
from langgraph.graph import StateGraph,START,END,MessagesState
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.graph.message import add_messages
from langchain_core.messages import HumanMessage,AIMessage
from dotenv import load_dotenv
from langchain_google_genai import ChatGoogleGenerativeAI 

load_dotenv()


llm = ChatGoogleGenerativeAI(model="gemini-3.8-flash",temperature=0.2) 

class StateSchema(TypedDict):
    messages: Annotated[list[str],add_messages]


def llm_call(state:StateSchema):
    messages = state['messages']
    # print("Human : ",messages[-1].content)
    # res = llm.invoke(messages)
    # print("AI : ",res.content[0]['text'])
    # return {'messages': [AIMessage(content=res.content[0]['text'])]}
    return {"messages":[AIMessage(content="Response received successfully from LLM")]}


builder = StateGraph(StateSchema)
builder.add_node('llm_call_node',llm_call)

builder.add_edge(START,'llm_call_node')
builder.add_edge('llm_call_node',END)

graph = builder.compile()


# res = graph.invoke({'messages':[HumanMessage(content="kya bolta bro ?")]})



