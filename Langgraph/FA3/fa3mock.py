# ============================================================
# CORRECTIVE RAG
# 2 PDFs + Human Interrupt + Conditional Web Search
# + Final Summarization + AWS ChatBedrockConverse
# ============================================================

# TODO 1: Install required packages
# pip install langchain langchain-community langchain-aws
# pip install langgraph faiss-cpu pypdf boto3 tavily-python

import os

from typing import TypedDict, List

from langchain_core.documents import Document
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.messages import HumanMessage

from langchain_community.document_loaders import PyPDFLoader
from langchain_community.vectorstores import FAISS
from langchain_community.embeddings import BedrockEmbeddings
from langchain_community.tools.tavily_search import TavilySearchResults

from langchain_aws import ChatBedrockConverse
from langchain_ollama import ChatOllama,OllamaEmbeddings

from langgraph.graph import StateGraph, START, END
from langgraph.types import interrupt, Command
from langgraph.checkpoint.memory import MemorySaver
from dotenv import load_dotenv
load_dotenv()

# ============================================================
# 1. AWS CHATBEDROCK
# ============================================================

llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)
embeddings = OllamaEmbeddings(model="nomic-embed-text")

# ============================================================
# 3. STATE
# ============================================================

class RAGState(TypedDict):
    question: str
    documents: List[Document]
    retrieved_docs: List[Document]
    answer: str
    confidence: str
    search_results: str
    final_answer: str
    summary: str


# ============================================================
# 4. LOAD TWO PDF DOCUMENTS
# ============================================================

def load_pdfs(state: RAGState):

    loader1 = PyPDFLoader("./data/sample_invoice.pdf")
    # loader2 = PyPDFLoader("research_paper_2.pdf")

    docs1 = loader1.load()
    # docs2 = loader2.load()

    documents = docs1

    return {
        "documents": documents
    }


# ============================================================
# 5. CREATE VECTOR DATABASE
# ============================================================

def create_vectorstore(state: RAGState):

    vectorstore = FAISS.from_documents(
        state["documents"],
        embeddings
    )

    # Store vector database globally for next node
    global retriever
    retriever = vectorstore.as_retriever(
        search_kwargs={"k": 4}
    )

    return {}


# ============================================================
# 6. RETRIEVE RELEVANT INFORMATION
# ============================================================

def retrieve_documents(state: RAGState):

    docs = retriever.invoke(
        state["question"]
    )

    return {
        "retrieved_docs": docs
    }


# ============================================================
# 7. GENERATE INITIAL ANSWER
# ============================================================

def generate_answer(state: RAGState):

    context = "\n\n".join(
        doc.page_content
        for doc in state["retrieved_docs"]
    )

    prompt = ChatPromptTemplate.from_template(
        """
        You are a RAG question-answering assistant.

        Answer the question ONLY using the retrieved
        document context.

        If the context is insufficient, clearly say that
        the available documents do not contain enough
        information.

        Context:
        {context}

        Question:
        {question}

        Answer:
        """
    )

    chain = prompt | llm

    response = chain.invoke({
        "context": context,
        "question": state["question"]
    })

    return {
        "answer": response.content
    }


# ============================================================
# 8. CHECK CONFIDENCE
# ============================================================

def check_confidence(state: RAGState):

    prompt = f"""
    Evaluate whether the following answer is sufficiently
    supported by the retrieved context.

    Question:
    {state["question"]}

    Answer:
    {state["answer"]}

    Retrieved Context:
    {" ".join(
        doc.page_content
        for doc in state["retrieved_docs"]
    )}

    Return ONLY one word:

    HIGH
    or
    LOW
    """

    response = llm.invoke(
        [HumanMessage(content=prompt)]
    )

    confidence = response.content.strip().upper()

    if "HIGH" in confidence:
        confidence = "HIGH"
    else:
        confidence = "LOW"

    return {
        "confidence": confidence
    }


# ============================================================
# 9. CONDITIONAL ROUTING
# ============================================================

def route_after_confidence(state: RAGState):

    if state["confidence"] == "LOW":
        return "web_search"

    return "human_review"


# ============================================================
# 10. TACIT WEB SEARCH
# ============================================================

def web_search(state: RAGState):

    search = TavilySearchResults(
        max_results=3
    )

    results = search.invoke(
        state["question"]
    )

    search_text = "\n\n".join(
        str(result)
        for result in results
    )

    return {
        "search_results": search_text
    }


# ============================================================
# 11. CORRECTIVE ANSWER AFTER WEB SEARCH
# ============================================================

def corrective_answer(state: RAGState):

    context = "\n\n".join(
        doc.page_content
        for doc in state["retrieved_docs"]
    )

    prompt = f"""
    You are a corrective RAG assistant.

    Answer the user's question using BOTH:

    1. Information retrieved from the PDFs.
    2. Additional web-search information.

    PDF CONTEXT:
    {context}

    WEB SEARCH:
    {state["search_results"]}

    QUESTION:
    {state["question"]}

    Give a clear and accurate answer.
    Do not invent information.
    """

    response = llm.invoke(
        [HumanMessage(content=prompt)]
    )

    return {
        "answer": response.content
    }


# ============================================================
# 12. HUMAN INTERRUPT
# ============================================================

def human_review(state: RAGState):

    review = interrupt(
        {
            "message": "Please review the generated answer.",
            "question": state["question"],
            "answer": state["answer"],
            "confidence": state["confidence"]
        }
    )

    if review == "reject":
        return {
            "answer": "The answer was rejected by the human reviewer."
        }

    if isinstance(review, dict):
        if "answer" in review:
            return {
                "answer": review["answer"]
            }

    return {}


# ============================================================
# 13. FINAL SUMMARIZATION FUNCTION
# ============================================================

def summarize_answer(state: RAGState):

    prompt = f"""
    Summarize the following final answer in 2-3 concise
    sentences.

    Question:
    {state["question"]}

    Final Answer:
    {state["answer"]}

    Return only the summary.
    """

    response = llm.invoke(
        [HumanMessage(content=prompt)]
    )

    return {
        "summary": response.content,
        "final_answer": state["answer"]
    }


# ============================================================
# 14. BUILD LANGGRAPH
# ============================================================

graph = StateGraph(RAGState)


# Add nodes
graph.add_node("load_pdfs", load_pdfs)
graph.add_node("create_vectorstore", create_vectorstore)
graph.add_node("retrieve", retrieve_documents)
graph.add_node("generate", generate_answer)
graph.add_node("confidence", check_confidence)
graph.add_node("web_search", web_search)
graph.add_node("corrective_answer", corrective_answer)
graph.add_node("human_review", human_review)
graph.add_node("summarize", summarize_answer)


# ============================================================
# 15. EDGES
# ============================================================

graph.add_edge(
    START,
    "load_pdfs"
)

graph.add_edge(
    "load_pdfs",
    "create_vectorstore"
)

graph.add_edge(
    "create_vectorstore",
    "retrieve"
)

graph.add_edge(
    "retrieve",
    "generate"
)

graph.add_edge(
    "generate",
    "confidence"
)


# Confidence-based routing
graph.add_conditional_edges(
    "confidence",
    route_after_confidence,
    {
        "web_search": "web_search",
        "human_review": "human_review"
    }
)


graph.add_edge(
    "web_search",
    "corrective_answer"
)

graph.add_edge(
    "corrective_answer",
    "human_review"
)

graph.add_edge(
    "human_review",
    "summarize"
)

graph.add_edge(
    "summarize",
    END
)


# ============================================================
# 16. CHECKPOINT FOR HUMAN INTERRUPT
# ============================================================

memory = MemorySaver()

app = graph.compile(
    checkpointer=memory
)

#### graph
print(app.get_graph().draw_ascii())


# ============================================================
# 17. RUN THE RAG
# ============================================================

question = input(
    "Enter your question: "
)

config = {
    "configurable": {
        "thread_id": "rag-1"
    }
}


result = app.invoke(
    {
        "question": question,
        "documents": [],
        "retrieved_docs": [],
        "answer": "",
        "confidence": "",
        "search_results": "",
        "final_answer": "",
        "summary": ""
    },
    config=config
)


# ============================================================
# 18. RESUME AFTER HUMAN INTERRUPT
# ============================================================

if "__interrupt__" in result:

    print("\nHuman Review Required")
    print(result["__interrupt__"])

    decision = input(
        "\nEnter 'approve' or 'reject': "
    )

    result = app.invoke(
        Command(
            resume=decision
        ),
        config=config
    )


# ============================================================
# 19. FINAL OUTPUT
# ============================================================

print("\n==============================")
print("FINAL ANSWER")
print("==============================")

print(result["final_answer"])

print("\n==============================")
print("SUMMARY")
print("==============================")

print(result["summary"])




# They gave us 2 pdfs about Q3 earnings of 2 companies and we had to do the process of loading, chunking, embedding and building vectorstores. And then build a corrective rag that retrieves context from those vectorstores. If the retrieved context is relevant to the question then proceed with generating the answer and if not then use tavily api to perform web search and generate answer based on web search result. They gave sample questions and answers but i’m not sure if implementing those are necessary since there was no mark distribution given.






