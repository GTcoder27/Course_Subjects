from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline
import os
from langchain_ollama import ChatOllama
from dotenv import load_dotenv
load_dotenv()


model = ChatOllama(model = 'qwen2.5:0.5b-instruct')

template1 = PromptTemplate(
    template="write a detail report on {topic}",
    input_variables=['topic']
)
template2 = PromptTemplate(
    template="write a 5 lines summary on the following text.: {text}",
    input_variables=['text']
)

chain = template1 | model | StrOutputParser() | template2 | model | StrOutputParser()

res = chain.invoke({'topic':'kaziranga national park India'})

print(res)









