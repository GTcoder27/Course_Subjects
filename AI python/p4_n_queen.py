import random

def calculate_conflicts(state):
    n = len(state)
    conflicts = 0
    for i in range(n):
        for j in range(i + 1, n):
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                conflicts += 1
    return conflicts

def get_best_neighbor(state):
    n = len(state)
    min_conflicts = calculate_conflicts(state)
    best_state = state[:]
    
    for row in range(n):
        original_col = state[row]
        for col in range(n):
            if col != original_col:
                state[row] = col
                current_conflicts = calculate_conflicts(state)
                if current_conflicts < min_conflicts:
                    min_conflicts = current_conflicts
                    best_state = state[:]
        state[row] = original_col
    return best_state

def hill_climbing(n):
    state = [random.randint(0, n-1) for _ in range(n)]
    while True:
        next_state = get_best_neighbor(state)
        if calculate_conflicts(next_state) >= calculate_conflicts(state):
            break
        state = next_state
    return state

def solve_n_queens(n):
    attempts = 0
    while True:
        attempts += 1
        result = hill_climbing(n)
        if calculate_conflicts(result) == 0:
            print(f"Solution found after {attempts} attempt(s):")
            return result

def print_board(state):
    n = len(state)
    for row in range(n):
        line = ""
        for col in range(n):
            line += "Q " if state[row] == col else ". "
        print(line)
    print()

# Set N
n = 8  # You can change this to any N >= 4
solution = solve_n_queens(n)
print_board(solution)
