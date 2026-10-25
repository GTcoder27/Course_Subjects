from langgraph.graph import StateGraph,START ,END
from typing import TypedDict,Literal
from langchain_ollama import ChatOllama




llm = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2,max_token=100)

class QuadraticState(TypedDict):
    a: int
    b: int
    c: int
    equation: str
    discriminant: float
    roots: str

def show_equation(state:QuadraticState):
    equation = f'{state['a']}x2 {state['b']}x {state['c']}'
    return {'equation' : equation }
    
def calculate_discriminant(state:QuadraticState):
    discriminant = (state['b'] ** 2) - (4 * state['a'] * state['c']) 
    return {'discriminant':discriminant}

def calculate_no_real_roots(state:QuadraticState):
    roots = 'No real roots'
    return {'roots':roots}

def calculate_real_roots(state:QuadraticState):
    root1 = (-state['b'] - state['discriminant'] ** 0.5) / (2 * state['a'])  
    root2 = (-state['b'] + state['discriminant'] ** 0.5) / (2 * state['a'])
    roots = f'root1 = {round(root1,2)}, root2 = {round(root2,2)}'
    return {'roots': roots}

def calculate_repeated_roots(state:QuadraticState):
    root = (-state['b']) / (2 * state['a'])  
    roots = f'root1 = {round(root,2)}, root2 = {round(root,2)}'
    return {'roots':roots}

def check_condition(state:QuadraticState) -> Literal["real_roots","no_real_roots","repeated_roots"]:
    discriminant = state['discriminant']
    res = ""
    if discriminant == 0:
        res = 'repeated_roots'
    elif discriminant > 0:
        res = 'real_roots'
    else:
        res = 'no_real_roots'
    return res


graph = StateGraph(QuadraticState)

graph.add_node('show_equation',show_equation)
graph.add_node('discriminant',calculate_discriminant)
graph.add_node('no_real_roots',calculate_no_real_roots)
graph.add_node('real_roots',calculate_real_roots)
graph.add_node('repeated_roots',calculate_repeated_roots)

graph.add_edge(START,'show_equation')
graph.add_edge('show_equation','discriminant')

graph.add_conditional_edges('discriminant',check_condition)

graph.add_edge('no_real_roots',END)
graph.add_edge('real_roots',END)
graph.add_edge('repeated_roots',END)

workflow = graph.compile()

inital_state = {
    'a':4,
    'b':-5,
    'c':-4
}
final_state = workflow.invoke(inital_state)
print(final_state)




