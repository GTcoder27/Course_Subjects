from langchain_core.runnables import RunnableParallel,RunnableBranch, RunnableLambda
from langchain_ollama import ChatOllama
from langchain_core.output_parsers import StrOutputParser, PydanticOutputParser 
from langchain_core.prompts import PromptTemplate
from typing import Literal
from pydantic import BaseModel, Field


model = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)

class Feedback(BaseModel):
    sentiment : Literal['positive','negative'] = Field(description="Give the sentiment of the feedback")

parser1 = StrOutputParser()
parser2 = PydanticOutputParser(pydantic_object=Feedback)

prompt1 = PromptTemplate(
    template="Classify the sentiment of the following feedback text into positive or negative.{format_instruction}\n Feedback:{feedback}",
    input_variables=['feedback'],
    partial_variables={'format_instruction':parser2.get_format_instructions()}
)

classifier_chain = prompt1 | model | parser2
feedback = 'This is a very terrible phone not working and diplay is broken '
res = classifier_chain.invoke({'feedback':feedback})
print(res)

prompt2 = PromptTemplate(
    template="write an message of thank you. \n {feedback}",
    input_variables=['feedback']
)

prompt3 = PromptTemplate(
    template="write an message to support team about this feedback. \n {feedback}",
    input_variables=['feedback']
)

branch_chain = RunnableBranch(
    (lambda x:x.sentiment == 'positive',prompt2 | model | parser1),
    (lambda x:x.sentiment == 'negative',prompt3 | model | parser1),
    RunnableLambda(lambda x: "could not find sentiment") 
)

chain = classifier_chain | branch_chain
feedback = 'This is a very terrible phone not working and diplay is broken '
res = chain.invoke({'feedback':feedback})

print(res)



