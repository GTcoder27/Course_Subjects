from langchain_ollama import ChatOllama
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate,ChatPromptTemplate

model = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)

template1 = PromptTemplate(
    template="give information about {topic}",
    input_variables=['topic']
)
template2 = PromptTemplate(
    template="give 5 line summary of the following text : {text}",
    input_variables=['text']
)
parser = StrOutputParser()
chain = template1 | model | parser | model | parser
res = chain.invoke({'topic':'Indian cricket team'})
print(res) 

# chain.get_graph().print_ascii()



















