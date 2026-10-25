from langchain_core.runnables import RunnableParallel
from langchain_ollama import ChatOllama
from langchain_core.output_parsers import StrOutputParser 
from langchain_core.prompts import PromptTemplate


model1 = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)
model2 = ChatOllama(model='qwen2.5:0.5b-instruct',temperature=0.2)

prompt1 = PromptTemplate(
    template="generate notes on the following text in small 5 points : {text}",
    input_variables=['text']
)
prompt2 = PromptTemplate(
    template="generate 5 questions on the following text : {text}",
    input_variables=['text']
)
prompt3 = PromptTemplate(
    template="merge both provided notes and questions into one document.Notes:{notes} Questions:{questions}",
    input_variables=['notes','questions']
)
parser = StrOutputParser()
parallel_chain = RunnableParallel({
    'notes': prompt1 | model1 | parser,
    'questions': prompt2 | model2 | parser
})
merge_chain = prompt3 | model1 | parser
chain = parallel_chain | merge_chain | parser

text = '''The following are a set of methods intended for regression in which the target value is expected to be a linear combination of the features. In mathematical notation, the predicted value 
 can be written as:

Across the module, we designate the vector 
 as coef_ and 
 as intercept_.

To perform classification with generalized linear models, see Logistic regression.

1.1.1. Ordinary Least Squares
LinearRegression fits a linear model with coefficients 
 to minimize the residual sum of squares between the observed targets in the dataset, and the targets predicted by the linear approximation. Mathematically it solves a problem of the form:LinearRegression takes in its fit method arguments X, y, sample_weight and stores the coefficients 
 of the linear model in its coef_ and intercept_ attributes:

from sklearn import linear_model
reg = linear_model.LinearRegression()
reg.fit([[0, 0], [1, 1], [2, 2]], [0, 1, 2])
LinearRegression()
reg.coef_
array([0.5, 0.5])
reg.intercept_
0.0
The coefficient estimates for Ordinary Least Squares rely on the independence of the features. When features are correlated and some columns of the design matrix 
 have an approximately linear dependence, the design matrix becomes close to singular and as a result, the least-squares estimate becomes highly sensitive to random errors in the observed target, producing a large variance. This situation of multicollinearity can arise, for example, when data are collected without an experimental design.''' 


res = parallel_chain.invoke({'text':text})
print(res)














