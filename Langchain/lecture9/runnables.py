from langchain_core.runnables import RunnableSequence,RunnableParallel,RunnablePassthrough,RunnableLambda,RunnableBranch
from langchain_core.prompts import PromptTemplate
from langchain_ollama import ChatOllama
from langchain_core.output_parsers import StrOutputParser,PydanticOutputParser
from pydantic import BaseModel ,Field
from typing import Literal

model = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)


###########
# Runnable Sequence
###########
# prompt1 = PromptTemplate(
#     template="give information about {topic}",
#     input_variables=['topic']
# )
# prompt2 = PromptTemplate(
#     template="give 5 line summary of the following text : {text}",
#     input_variables=['text']
# )
# parser = StrOutputParser()
# chain = RunnableSequence(prompt1 ,model , parser ,prompt2, model , parser)
# res = chain.invoke({'topic':'Indian cricket team'})
# print(res)



###########
# RunnableParallel
 ###########
# prompt1 = PromptTemplate(
#     template="generate a tweet about topic : {topic}",
#     input_variables=['topic']
# )
# prompt2 = PromptTemplate(
#     template="generate a linkedIn post about topic : {topic}",
#     input_variables=['topic']
# )
# parser = StrOutputParser()
# parallel_chain = RunnableParallel({
#     'tweet': RunnableSequence(prompt1,model,parser),
#     'linkedIn':RunnableSequence(prompt2,model,parser)
# })
# res = parallel_chain.invoke({'topic':'Indian cricket team won world cup'})
# print(res['tweet'])
# print(res['linkedIn'])



###########
# Runnable Passthrough (gives output same as input)
###########
# prompt1 = PromptTemplate(
#     template="generate a simple joke"
# )
# prompt2 = PromptTemplate(
#     template="explain the following joke : {joke}",
#     input_variables=['joke']
# )
# parser = StrOutputParser()
# parallel_chain = RunnableParallel({
#     'joke': RunnablePassthrough(),
#     'joke_explaination': RunnableSequence(prompt2,model,parser)
# })
# chain = RunnableSequence(prompt1,model,parser,parallel_chain)
# res = chain.invoke({})
# print(res['joke'])
# print(res['joke_explaination'])




###########
# RunnableLambda
###########
# prompt1 = PromptTemplate(
#     template="generate a simple joke"
# )
# prompt2 = PromptTemplate(
#     template="explain the following joke : {joke}",
#     input_variables=['joke']
# )
# parser = StrOutputParser()
# parallel_chain = RunnableParallel({
#     'joke': RunnablePassthrough(),
#     'joke_explaination': RunnableSequence(prompt2,model,parser)
# })
# def word_counter(joke):
#     print(len(joke.split(' ')))
#     return joke
# chain = RunnableSequence(prompt1,model,parser,RunnableLambda(word_counter),parallel_chain)
# res = chain.invoke({})
# print(res['joke'])
# print(res['joke_explaination'])





###########
# Runnable Branch 
###########

class Feedback(BaseModel):
    sentiment : Literal['positive','negative'] = Field(description="Give the sentiment of the feedback")

parser1 = StrOutputParser()
parser2 = PydanticOutputParser(pydantic_object=Feedback)

prompt1 = PromptTemplate(
    template="Classify the sentiment of the following feedback text into positive or negative.{format_instruction} \n Feedback:{feedback}",
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














