import os
from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline
from langchain_core.messages import SystemMessage, AIMessage,HumanMessage 
from langchain_core.prompts import ChatPromptTemplate,MessagesPlaceholder
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


model = ChatHuggingFace(llm=llm)
chat_template = ChatPromptTemplate([
    ('system','you are doctor name MR.smith'),
    MessagesPlaceholder(variable_name='chat_history'),
    ('human','{query}')
])

chat_history = []


while True:
    query = input("ASK anything : ")
    prompt = chat_template.invoke({'chat_history':chat_history,'query':query})
    res = model.invoke(prompt)
    chat_history.append(HumanMessage(content=query))
    chat_history.append(AIMessage(content=res.content))
    print("AI Response : ",res)
    # print("$$$$$$$$$$")
    # print(prompt)
    # print("##########")





