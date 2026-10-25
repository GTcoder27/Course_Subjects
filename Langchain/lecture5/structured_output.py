from langchain_openai import ChatOpenAI
from dotenv import load_dotenv
from typing import TypedDict,Annotated
load_dotenv()

model = ChatOpenAI(model='gpt-4')

class Review(TypedDict):
    summary:Annotated[str,"A brief summary or review"]
    sentiment: str

structured_model = model.with_structured_output(Review)

result = structured_model.invoke("what is capital of india ?")

print(result)
print(result['summary'])
print(result['sentiment'])



