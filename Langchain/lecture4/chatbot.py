from langchain_huggingface import ChatHuggingFace,HuggingFacePipeline
from langchain_core.messages import SystemMessage, AIMessage,HumanMessage 
import os

os.environ['HF_HOME'] = '/run/media/gtcoder/Data/Coding/HuggingFace'
llm = HuggingFacePipeline.from_model_id(
    model_id='TinyLlama/TinyLlama-1.1B-Chat-v1.0',
    task='text-generation',
    pipeline_kwargs=dict(
        temperature=0.5,
        # max_new_tokens=100
    )
)
model = ChatHuggingFace(llm=llm)
messages = [
    SystemMessage(content="you are doctor"),
    HumanMessage(content="tell me what are cells")
]
res = model.invoke(messages)
print(res.content)
print("Now lets chat with doctor")

while True:
    prompt = input("Ask me : ")
    messages.append(HumanMessage(content=prompt))
    res = model.invoke(messages)
    messages.append(AIMessage(content=res.content))
    print("AI agent : ",res.content)





