from langchain_core.output_parsers import StrOutputParser,PydanticOutputParser
from langchain_core.prompts import PromptTemplate
from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline
import os
from langchain_ollama import ChatOllama
from pydantic import BaseModel,Field
from dotenv import load_dotenv
load_dotenv()


class Person(BaseModel):
    name : str = Field(description="name of the person")
    age : int = Field(description="age of the person")

parser = PydanticOutputParser(pydantic_object=Person)

model = ChatOllama(model = 'qwen2.5:0.5b-instruct',temperature=0.2)

template = PromptTemplate(
    template="generate a name and age of fictional {place} person \n {format_instruction}",
    input_variables=['place'],
    partial_variables={'format_instruction':parser.get_format_instructions()}
)

chain = template | model | parser

res = chain.invoke({'place':'India'})

print(res)









