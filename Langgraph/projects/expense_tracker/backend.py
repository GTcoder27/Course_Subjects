from langchain_aws import ChatBedrockConverse
from langchain_ollama import ChatOllama,OllamaEmbeddings
from typing import TypedDict, Literal,List,Dict,Annotated,Any
from langgraph.graph import StateGraph,START,END,MessagesState
from pydantic import BaseModel,Field
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.checkpoint.sqlite import SqliteSaver
from langgraph.graph.message import add_messages
import sqlite3
from langchain_core.messages import HumanMessage,AIMessage,SystemMessage,BaseMessage,ToolMessage
import operator
from langchain_core.tools import tool
import uuid
from langgraph.store.memory import InMemoryStore
from langgraph.types import Command,interrupt
from langchain.agents import create_agent
from langchain.agents.middleware import HumanInTheLoopMiddleware,PIIMiddleware,SummarizationMiddleware
from langgraph.prebuilt import ToolNode, tools_condition
from langchain.tools import ToolException
from datetime import date
import os



llm = ChatOllama(model='qwen3:1.7b',temperature=0.1)



############ Database ############

os.makedirs("database", exist_ok=True)
conn1 = sqlite3.connect("database/expenses.db",check_same_thread=False)
expenses_db = conn1.cursor()
expenses_db.execute("""
CREATE TABLE IF NOT EXISTS expenses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    amount REAL NOT NULL,
    description TEXT,
    date TEXT
)
""")
conn1.commit()


############ Tools ##############
@tool
def add_expense(amount: float, description: str, expense_date: str):
    """Add a new expense."""
    cursor = conn1.cursor()
    cursor.execute(
        """
        INSERT INTO expenses (amount, description, date)
        VALUES (?, ?, ?)
        """,
        (amount, description, expense_date)
    )
    conn1.commit()
    return {
        "status": "success",
        "id": cursor.lastrowid,
        "amount": amount,
        "description": description,
        "date": expense_date
    }

@tool
def get_expenses(expense_date: str):
    """Get all expenses for a specific date."""
    cursor = conn1.cursor()
    cursor.execute(
        """
        SELECT id, amount, description, date
        FROM expenses
        WHERE date = ?
        """,
        (expense_date,)
    )
    return cursor.fetchall()

@tool
def get_total_expense(expense_date: str):
    """Get total amount spent on a particular date."""
    cursor = conn1.cursor()
    cursor.execute(
        """
        SELECT COALESCE(SUM(amount), 0)
        FROM expenses
        WHERE date = ?
        """,
        (expense_date,)
    )
    return {
        "date": expense_date,
        "total": cursor.fetchone()[0]
    }


tools = [add_expense,get_expenses,get_total_expense]
tools_node = ToolNode(tools)
llm_with_tools = llm.bind_tools(tools)



class State(TypedDict):
    messages: Annotated[list[str],add_messages]


def llm_node(state:State):
    today = date.today()
    prompt = f"""
    You are an expense tracker agent.
    You can call tools to add data or read data from database.
    Database table:
    expenses(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        amount REAL NOT NULL,
        description TEXT,
        date TEXT
    )
    Note: 
    1. After the tool returns its result, explain the result to the user in one line.
    2. calculate date based on today's date -> {today}.
    """
    res = llm_with_tools.invoke([SystemMessage(content=prompt)] + state['messages'])
    # print(res)
    return {'messages': [res]}


graph = StateGraph(State)
graph.add_node('llm_node',llm_node)
graph.add_node('tools',tools_node)

graph.add_edge(START,'llm_node')
graph.add_conditional_edges('llm_node',tools_condition,{'tools':'tools',END:END})
graph.add_edge('tools','llm_node')

conn2 = sqlite3.connect("database/conversation.db",check_same_thread=False)
workflow = graph.compile(checkpointer=SqliteSaver(conn=conn2))



while True:
    thread_id = uuid.uuid4()
    config = {'configurable':{'thread_id':thread_id}}

    user_message = input("Ask -> ")
    if user_message.strip().lower() in ['exit','bye','quit']:
        break
    res = workflow.invoke({'messages':[HumanMessage(content=user_message)]},config=config)
    print('AI -> ',res['messages'][-1].content)





