from collections import deque

# Capacities of jugs
jug1_capacity = 4
jug2_capacity = 3
goal_state = (2, 0)

# Function to get all possible next states
def get_next_states(state):
    x, y = state
    next_states = set()

    # Fill Jug1
    next_states.add((jug1_capacity, y))
    # Fill Jug2
    next_states.add((x, jug2_capacity))
    # Empty Jug1
    next_states.add((0, y))
    # Empty Jug2
    next_states.add((x, 0))
    # Pour Jug1 -> Jug2
    transfer = min(x, jug2_capacity - y)
    next_states.add((x - transfer, y + transfer))
    # Pour Jug2 -> Jug1
    transfer = min(y, jug1_capacity - x)
    next_states.add((x + transfer, y - transfer))

    return next_states

def bfs():
    visited = set()
    queue = deque()
    parent = {}

    start = (0, 0)
    queue.append(start)
    visited.add(start)
    parent[start] = None

    while queue:
        current = queue.popleft()
        if current == goal_state:
            break
        for next_state in get_next_states(current):
            if next_state not in visited:
                visited.add(next_state)
                parent[next_state] = current
                queue.append(next_state)

    # Reconstruct path
    path = []
    state = goal_state
    while state:
        path.append(state)
        state = parent[state]
    path.reverse()
    return path

# Run BFS
solution = bfs()

# Print solution path
print("Sequence of operations:")
for step in solution:
    print(step)
