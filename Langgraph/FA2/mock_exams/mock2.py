# =====================================================================
# FA2 Mock Hands-on Assessment - Problem Statement 2
# Time Travel with Persistent Checkpoints: Machine Translation & Summarization
# =====================================================================
# NOTE: The import lines were not visible/legible in the uploaded
# screenshots. Standard imports required to satisfy every downstream
# reference (TypedDict, ChatBedrockConverse, StateGraph, START/END,
# InMemorySaver) are added below.
# =====================================================================
from typing import TypedDict
from langchain_aws import ChatBedrockConverse
from langgraph.graph import StateGraph, START, END
from langgraph.checkpoint.memory import InMemorySaver
from langchain_ollama import ChatOllama


# ============= TODO - YOUR CODE HERE ============
# LLM setup
#
# Instantiate a ChatBedrockConverse LLM and expose it as `llm` for the
# rest of the file. Downstream nodes call `llm.invoke(...)`, so the
# variable must be named `llm`.
# =====================================================================
llm = ChatBedrockConverse(
    model_id="amazon.nova-lite-v1:0",
    region_name='us-east-1',
    temperature=0.6,
    max_tokens=800
)

llm = ChatOllama(model='qwen2.5:1.5b',temperature=0.2,max_token=200)


# ============= GIVEN - DO NOT MODIFY ============
# Target language for the pipeline
# =====================================================================
TARGET_LANGUAGE = "Hindi"  # change to "French" if preferred

# ============= GIVEN - DO NOT MODIFY ============
# State schema - downstream nodes read these exact field names.
#   source_text : English input document
#   translated  : Version 1 - formal translation
#   summary     : Version 2 - concise summary
#   refined     : Version 3 - reader-friendly refinement
# =====================================================================
class DocState(TypedDict):
    source_text: str
    translated: str
    summary: str
    refined: str


# ============= TODO - YOUR CODE HERE ============
# Node 1: translate_text
#
# Use `llm` to translate state['source_text'] from English into
# TARGET_LANGUAGE using a formal tone.
# Return {"translated": <the translation>}
# =====================================================================
def translate_text(state: DocState):
    response = llm.invoke(f""" Translate the following English text into {TARGET_LANGUAGE}
    using a formal tone. Only output the translation, no extra commentary.

    Text: {state['source_text']}
    """)
    result = response.content.strip()
    print(f"\n[translate_text] Version 1 ({TARGET_LANGUAGE}):\n{result}")
    return {"translated": result}


# ============= TODO - YOUR CODE HERE ============
# Node 2: summarize_text
#
# Use `llm` to produce a concise summary of state['translated'].
# Keep the summary in TARGET_LANGUAGE.
# Return {"summary": <the summary>}
# =====================================================================
def summarize_text(state: DocState):
    response = llm.invoke(f""" Produce a concise summary of the following {TARGET_LANGUAGE}
    text. Keep the summary in {TARGET_LANGUAGE}. Only output the summary, no extra text.

    Text: {state['translated']}
    """)
    result = response.content.strip()
    print(f"\n[summarize_text] Version 2 (summary, {TARGET_LANGUAGE}):\n{result}")
    return {"summary": result}


# ============= TODO - YOUR CODE HERE ============
# Node 3: refine_summary
#
# Use `llm` to refine state['summary'] for readability and public-release tone.
# Keep the refined text in TARGET_LANGUAGE. Do NOT add, remove, or change any
# facts (names, numbers, entities). Do not translate back to English.
# Return {"refined": <the refined text>}
# =====================================================================
def refine_summary(state: DocState):
    response = llm.invoke(f""" Refine the following {TARGET_LANGUAGE} summary for readability
    and a public-release tone. Keep the refined text entirely in {TARGET_LANGUAGE}.
    Do NOT add, remove, or change any facts (names, numbers, entities).
    Do NOT translate the text back to English. Only output the refined text.

    Text: {state['summary']}
    """)
    result = response.content.strip()
    print(f"\n[refine_summary] Version 3 (refined, {TARGET_LANGUAGE}):\n{result}")
    return {"refined": result}


# ============= TODO - YOUR CODE HERE ============
# Graph builder
#
# Wire three nodes into a StateGraph:
#   START -> translate_text -> summarize_text -> refine_summary -> END
#
# Node names in the graph (must match exactly):
#   "translate_text", "summarize_text", "refine_summary"
#
# Compile with an InMemorySaver checkpointer so state is persisted after
# every node (this is what makes time travel possible).
# Expose the compiled graph via a function called `build_graph()` that
# returns it (main() calls build_graph()).
# =====================================================================
def build_graph():
    workflow = StateGraph(DocState)

    workflow.add_node("translate_text", translate_text)
    workflow.add_node("summarize_text", summarize_text)
    workflow.add_node("refine_summary", refine_summary)

    workflow.add_edge(START, "translate_text")
    workflow.add_edge("translate_text", "summarize_text")
    workflow.add_edge("summarize_text", "refine_summary")
    workflow.add_edge("refine_summary", END)

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


# ============= PARTIALLY GIVEN - COMPLETE THE TODOs ============
# Test harness
#
# Runs the full pipeline, then walks through the time-travel demo:
# inspect checkpoints, roll back to Version 1, and replay to regenerate
# Versions 2 and 3 from that point.
# =====================================================================
def run_test(app, source_text, thread_id="test_thread"):
    config = {"configurable": {"thread_id": thread_id}}

    # 1. Run the full pipeline (V1 -> V2 -> V3)
    final_state = app.invoke({"source_text": source_text}, config=config)
    print("\nFinal State after full pipeline:")
    print(final_state)

    # ============= TODO - YOUR CODE HERE ============
    # 2. Show all saved checkpoints. Each snapshot's `.next` field tells us
    #    which node is about to run at that point:
    #      next == ('translate_text',) -> nothing done yet
    #      next == ('summarize_text',) -> V1 done (translated)
    #      next == ('refine_summary',) -> V2 done (summary)
    #      next == ()                  -> V3 done (refined)  [end]
    #    Fetch the state history for this thread and print each checkpoint's
    #    `.next` value along with its checkpoint_id. Store the history in a
    #    variable called `history` - you'll need it in the next step.
    # =====================================================================
    history = list(app.get_state_history(config))
    print("\nAll saved checkpoints (newest first):")
    for snapshot in history:
        checkpoint_id = snapshot.config["configurable"]["checkpoint_id"]
        print(f"Checkpoint ID: {checkpoint_id} | Next: {snapshot.next}")

    # ============= TODO - YOUR CODE HERE ============
    # 3. Time travel: pick the checkpoint that is about to run summarize_text.
    #    That's V1 by definition - translation is done, summary hasn't started.
    #    Store the selected snapshot in a variable called `v1`, then print
    #    its checkpoint_id and v1.values["translated"].
    # =====================================================================
    v1 = None
    for snapshot in history:
        if snapshot.next == ("summarize_text",):
            v1 = snapshot
            break

    if v1 is None:
        print("\nCould not locate the V1 checkpoint (before summarize_text).")
        return

    print("\nSelected checkpoint V1 (about to run summarize_text):")
    print("Checkpoint ID:", v1.config["configurable"]["checkpoint_id"])
    print("Translated text (V1):", v1.values["translated"])

    # ============= TODO - YOUR CODE HERE ============
    # 4. Replay from V1 to regenerate V2 and V3.
    #    HINT: passing None as the input to app.invoke tells LangGraph
    #    "continue from this checkpoint". Use v1.config as the config.
    #    Print the regenerated summary and refined text.
    # =====================================================================
    replayed_state = app.invoke(None, config=v1.config)
    print("\nRegenerated Version 2 (summary) after replay from V1:")
    print(replayed_state["summary"])
    print("\nRegenerated Version 3 (refined) after replay from V1:")
    print(replayed_state["refined"])


# ============= GIVEN - DO NOT MODIFY ============
# Entry point
# =====================================================================
def main():
    app = build_graph()
    display_graph(app)

    print("\n========== TEST CASE 1 ==========")
    source = (
        "The city council approved a new policy to expand public transport. "
        "The plan adds 50 electric buses and three new metro lines over the next two years, "
        "aiming to cut traffic congestion and reduce carbon emissions across the region."
    )
    run_test(app, source, "doc_test_1")


if __name__ == "__main__":
    main()