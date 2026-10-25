from typing import TypedDict, Literal,List,Dict,Annotated
from langgraph.graph import StateGraph,START,END,MessagesState
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.graph.message import add_messages
from langchain_core.messages import HumanMessage 




class StateSchema(TypedDict):
    messages: Annotated[list[str],add_messages]
        

def llm_call(state:StateSchema):
    res = "HI how are you bro ."
    return {'messages': [res]}



builder = StateGraph(StateSchema)
builder.add_node('llm_call_node',llm_call)

builder.add_edge(START,'llm_call_node')
builder.add_edge('llm_call_node',END)

graph = builder.compile()


res = graph.invoke({'messages':[HumanMessage(content="kya bolta bro ?")]})
print(res)



