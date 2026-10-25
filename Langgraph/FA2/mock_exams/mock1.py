# =====================================================================
# FA2 Mock Hands-on Assessment - Problem Statement 1
# Multi-Tool AI Research Assistant
# =====================================================================
# NOTE: Lines 1-26 (imports) were not visible/legible in the uploaded
# screenshots. The imports below are the standard set required to make
# every downstream reference (TypedDict, ChatBedrockConverse, @tool,
# StateGraph, START/END, interrupt, Command, InMemorySaver) work.
# Adjust only if your actual boilerplate imports differ.
# =====================================================================
from typing import TypedDict, Optional
from langchain_aws import ChatBedrockConverse
from langchain_core.tools import tool
from langgraph.graph import StateGraph, START, END
from langgraph.types import interrupt, Command
from langgraph.checkpoint.memory import InMemorySaver
from langchain_ollama import ChatOllama


# ============= TODO - YOUR CODE HERE ============
# LLM setup
#
# Instantiate a ChatBedrockConverse LLM and expose it as `llm` for the
# rest of the file. Downstream nodes call `llm.invoke(...)` and
# `llm.bind_tools(...)`, so the variable must be named `llm`.
# =====================================================================
llm = ChatBedrockConverse(
    model_id="amazon.nova-lite-v1:0",
    region_name='us-east-1',
    temperature=0.6,
    max_tokens=500
)
llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)

# ============= GIVEN - DO NOT MODIFY ============
# State schema - downstream nodes read these exact field names.
# =====================================================================
class State(TypedDict):
    claim: str
    claim_type: str
    tool_used: str
    evidence: dict
    confidence: float
    human_feedback: Optional[str]
    final_report: str


# ============= GIVEN - DO NOT MODIFY ============
# Predefined evidence datasets - tools look up by exact claim text.
# =====================================================================
CLIMATE_DATA = {
    "India renewable energy capacity grew by 30% in 2024": [
        "IEA Report (2024): India's renewable capacity increased by 28% year-over-year.",
        "Bloomberg Energy Outlook: India ranked third globally in new solar installations.",
        "Government Data: Installed capacity reached 192 GW of renewables by late 2024."
    ],
    "Ocean temperatures hit record highs in 2024": [
        "NOAA Data: 2024 was the warmest year for ocean surface temperatures since 1880.",
        "Nature Climate Journal: Average Ocean temperature anomalies exceeded 1.2°C globally.",
        "UN Climate Division: Marine heatwaves affected 48% of world's oceans in 2024."
    ]
}

GENERAL_FACT_DATA = {
    "AI replaced 40% of human jobs in 2024": [
        "OECD Study: Automation affected about 11% of roles globally by 2024.",
        "McKinsey Report: AI adoption created new roles, offsetting large-scale job losses.",
        "Tech Review: AI shifted, not replaced, major segments of the workforce."
    ],
    "Global inflation rate dropped in 2024": [
        "IMF Report: Global inflation fell from 8.1% in 2023 to 6.3% in 2024.",
        "World Bank Data: Several economies saw moderation in core inflation post-Q2 2024.",
        "Financial Times: Central banks eased interest rates in response to declining inflation."
    ]
}

# ============= TODO - YOUR CODE HERE ============
# Tools
#
# Define two @tool-decorated functions:
#   climate_data_tool(query: str) - for environmental claims
#   general_fact_tool(query: str) - for economic/technological claims
#
# Each should look up `query` in the corresponding dataset above and
# return {"evidence": [<list of evidence strings>]}.
# If the query isn't found, return a placeholder list explaining that.
# =====================================================================
@tool
def climate_data_tool(query: str):
    """Look up environmental/climate evidence for a claim."""
    for key, values in CLIMATE_DATA.items():
        if query == key:
            return {"evidence": values}
    return {"evidence": ["Query not found in CLIMATE_DATA."]}


@tool
def general_fact_tool(query: str):
    """Look up general economic/technological evidence for a claim."""
    for key, values in GENERAL_FACT_DATA.items():
        if query == key:
            return {"evidence": values}
    return {"evidence": ["Query not found in GENERAL_FACT_DATA."]}


# ============= TODO - YOUR CODE HERE ============
# Tool registration
#
# Bind the tools to the LLM so decide_and_invoke_tool can route to them
# by name. You'll need three things available below:
#   - tools          : a list of tool functions
#   - tools_by_name  : a name -> tool lookup dict
#   - llm_with_tools : the LLM with tools bound
# =====================================================================
tools = [climate_data_tool, general_fact_tool]
tools_by_name = {t.name: t for t in tools}
llm_with_tools = llm.bind_tools(tools)


# ============= TODO - YOUR CODE HERE ============
# Node 1: classify_claim
#
# Use `llm` to classify state['claim'] into exactly one of:
#   [Environmental, Economic, Technological]
# Return {"claim_type": "<the single word>"}
# =====================================================================
def classify_claim(state: State):
    # Ask the LLM to classify the claim into one of the three domains.
    response = llm.invoke(f""" Classify the below data into exactly one of the following
    [Environmental, Economic, Technological]
    Do not give any extra text. Only one of the three from the given options
    Data: {state["claim"]}
    """)
    res = response.content.strip()
    print("Classified claim : ", res)
    return {"claim_type": res}


# ============= TODO - YOUR CODE HERE ============
# Node 2: decide_and_invoke_tool
#
# Use `llm_with_tools` to pick and invoke exactly ONE tool:
#   Environmental              -> climate_data_tool
#   Economic or Technological  -> general_fact_tool
# Pass the original claim text as the `query` argument.
# Return {"tool_used": <tool name>, "evidence": <tool output dict>}
#
# HINT: after invoking the LLM, check `response.tool_calls`.
#       Handle the case where it is empty (LLM didn't call a tool).
# =====================================================================
def decide_and_invoke_tool(state: State):
    prompt = f""" You need to use proper tool for further process.
    if claim_type == Environmental --> invoke climate_data_tool
    if claim_type == Economic or Technological --> invoke general_fact_tool

    Given: claim = {state["claim"]}
    claim_type = {state["claim_type"]}
    Do not give any extra text. Only give tool name to be invoked, and call
    the tool with the claim text as the query argument.
    """
    response = llm_with_tools.invoke(prompt)

    # Fallback: if the LLM didn't produce a tool call, decide deterministically
    # based on claim_type so the pipeline never breaks.
    if not response.tool_calls:
        fallback_tool = "climate_data_tool" if state["claim_type"] == "Environmental" else "general_fact_tool"
        tool_output = tools_by_name[fallback_tool].invoke({"query": state["claim"]})
        print("No tool_calls from LLM, used fallback tool:", fallback_tool)
        return {"tool_used": fallback_tool, "evidence": tool_output}

    for tool_call in response.tool_calls:
        tool_used = tool_call["name"]
        print("Tool invoked : ", tool_used)
        tool_output = tools_by_name[tool_used].invoke(tool_call["args"])
        print("Tool output: ", tool_output)
        return {"tool_used": tool_used, "evidence": tool_output}


# ============= TODO - YOUR CODE HERE ============
# Node 3: verify_confidence
#
# Use `llm` to score how well the evidence supports the claim.
# Return {"confidence": <float between 0.0 and 1.0>}
#
# Guidance in the prompt: prefer low confidence when evidence and claim
# don't strongly align. This is what triggers the human review branch.
# =====================================================================
def verify_confidence(state: State):
    response = llm.invoke(f""" You are a fact-verification assistant.
    Given the claim and the retrieved evidence below, assign a confidence
    score between 0.0 and 1.0 indicating how strongly the evidence supports
    the claim. Prefer a LOW confidence score (below 0.7) whenever the
    evidence and claim do not strongly / numerically align.
    Only output the float number, nothing else.

    Claim: {state["claim"]}
    Evidence: {state["evidence"]}
    """)
    raw = response.content.strip()
    try:
        confidence = float(raw)
    except ValueError:
        # Safety net in case the LLM adds stray text.
        import re
        match = re.search(r"[01](\.\d+)?", raw)
        confidence = float(match.group()) if match else 0.5
    print("Confidence score : ", confidence)
    return {"confidence": confidence}


# ============= TODO - YOUR CODE HERE ============
# Node 4: human_review
#
# Pause execution using interrupt() with a payload containing
# the claim, evidence, and confidence. Return {"human_feedback": <value>}.
# =====================================================================
def human_review(state: State):
    feedback = interrupt({
        "claim": state["claim"],
        "evidence": state["evidence"],
        "confidence": state["confidence"],
        "message": "Confidence below 0.7 - please review and provide feedback."
    })
    return {"human_feedback": feedback} 


# ============= TODO - YOUR CODE HERE ============
# Node 5: generate_final_report
#
# Use `llm` to produce a formatted verification report.
# Return {"final_report": <the text>}.
# The report must include Claim Type, Tool Invoked, Confidence, Decision,
# Human Feedback (or "Not Required"), and a two-line Final Report.
# =====================================================================
def generate_final_report(state: State):
    human_feedback = state.get("human_feedback") or "Not Required"
    decision = "Verified" if state["confidence"] >= 0.7 else "Verified (Human Approved)"

    response = llm.invoke(f""" Generate a concise two-line factual verification summary
    for the claim below, stating whether it is true, false, exaggerated, or partially true,
    based on the evidence provided.

    Claim: {state["claim"]}
    Evidence: {state["evidence"]}
    Confidence: {state["confidence"]}
    Human Feedback: {human_feedback}
    """)
    summary_text = response.content.strip()

    report = (
        f"Claim Type: {state['claim_type']}\n"
        f"Tool Invoked: {state['tool_used']}\n"
        f"Confidence: {state['confidence']}\n"
        f"Decision: {decision}\n"
        f"Human Feedback: {human_feedback}\n"
        f"Final Report: {summary_text}"
    )
    print("\nFinal Report:\n", report)
    return {"final_report": report}


# ============= TODO - YOUR CODE HERE ============
# Graph builder
#
# Wire five nodes into a StateGraph as per the instructions in the QP.
#
# Node names in the graph (must match exactly, since run_test references them):
#   "classify_claim", "retrieve_evidence", "verify_confidence",
#   "human_review", "finalize_report"
#
# Compile with checkpointer.
# Expose the compiled graph via a function called `build_graph()` that
# returns it (main() calls build_graph()).
# =====================================================================
def build_graph():
    workflow = StateGraph(State)

    workflow.add_node("classify_claim", classify_claim)
    workflow.add_node("retrieve_evidence", decide_and_invoke_tool)
    workflow.add_node("verify_confidence", verify_confidence)
    workflow.add_node("human_review", human_review)
    workflow.add_node("finalize_report", generate_final_report)

    workflow.add_edge(START, "classify_claim")
    workflow.add_edge("classify_claim", "retrieve_evidence")
    workflow.add_edge("retrieve_evidence", "verify_confidence")

    # Conditional routing: >= 0.7 auto-finalize, otherwise human review first.
    workflow.add_conditional_edges(
        "verify_confidence",
        lambda state: "finalize_report" if state["confidence"] >= 0.7 else "human_review",
        {"finalize_report": "finalize_report", "human_review": "human_review"}
    )
    workflow.add_edge("human_review", "finalize_report")
    workflow.add_edge("finalize_report", END)

    checkpointer = InMemorySaver()
    app = workflow.compile(checkpointer=checkpointer)
    return app


# ============= TODO - YOUR CODE HERE ============
# Graph display
#
# Implement a `display_graph(app)` function that prints the compiled
# graph structure (ASCII view is enough). main() will call it.
# =====================================================================
def display_graph(app):
    try:
        print(app.get_graph().draw_ascii())
    except Exception as e:
        print("Could not render ASCII graph:", e)
        print("Nodes:", list(app.get_graph().nodes.keys()))


# ============= PARTIALLY GIVEN - COMPLETE THE TODO ============
# Test
# =====================================================================
def run_test(app, claim, thread_id="test_thread"):
    config = {"configurable": {"thread_id": thread_id}}

    result = app.invoke({"claim": claim}, config=config)
    print("\nInitial Output:\n", result)

    # ============= TODO - YOUR CODE HERE ============
    # Implement the interrupt handling: prompt for human feedback and
    # resume the graph with Command(resume=<feedback>).
    # =====================================================================
    if "__interrupt__" in result:
        interrupt_payload = result["__interrupt__"][0].value
        print("\n--- Human Review Triggered ---")
        print("Review payload:", interrupt_payload)
        feedback = input(
            "Enter human feedback (press Enter to accept default 'Verified after manual review.'): "
        ).strip()
        if not feedback:
            feedback = "Verified after manual review."
        result = app.invoke(Command(resume=feedback), config=config)
        print("\nFinal Output after Human Review:\n", result)
    else:
        print("\nNo human review required. Claim auto-verified.")


def main():
    app = build_graph()
    display_graph(app)

    print("\n========== TEST CASE 1: Technological (HIL expected) ==========")
    run_test(app, "AI replaced 40% of human jobs in 2024", "claim_test_1")

    print("\n========== TEST CASE 2: Environmental (Auto-Verified) ==========")
    run_test(app, "Ocean temperatures hit record highs in 2024", "claim_test_2")


if __name__ == "__main__":
    main()