from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline,HuggingFaceEndpoint
import os
from dotenv import load_dotenv
load_dotenv()


os.environ['HF_HOME'] = '/run/media/gtcoder/Data/Coding/HuggingFace'

model_id = 'Qwen/Qwen2.5-0.5B-Instruct'
llm = HuggingFacePipeline.from_model_id(
    model_id=model_id,
    task='text-generation',
    pipeline_kwargs=dict(
        temperature=0.5,
        max_new_tokens=100
    )
)

model = ChatHuggingFace(llm = llm)

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









