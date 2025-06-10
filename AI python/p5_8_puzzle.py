import heapq

class PuzzleState:
    def __init__(self, grid, g_cost=0, parent=None, move=""):
        self.grid = grid
        self.g_cost = g_cost
        self.parent = parent
        self.move = move
        self.empty_pos = self.find_empty()
        
    def find_empty(self):
        for i in range(3):
            for j in range(3):
                if self.grid[i][j] == '_':
                    return (i, j)
    
    def manhattan_distance(self, goal):
        """Manhattan distance heuristic"""
        distance = 0
        for i in range(3):
            for j in range(3):
                if self.grid[i][j] != '_':
                    value = int(self.grid[i][j])
                    goal_row, goal_col = divmod(value - 1, 3)
                    distance += abs(i - goal_row) + abs(j - goal_col)
        return distance
    
    def f_cost(self, goal):
        return self.g_cost + self.manhattan_distance(goal)
    
    def get_neighbors(self):
        neighbors = []
        row, col = self.empty_pos
        moves = [(-1, 0, "UP"), (1, 0, "DOWN"), (0, -1, "LEFT"), (0, 1, "RIGHT")]
        
        for dr, dc, move_name in moves:
            new_row, new_col = row + dr, col + dc
            if 0 <= new_row < 3 and 0 <= new_col < 3:
                new_grid = [row[:] for row in self.grid]
                new_grid[row][col], new_grid[new_row][new_col] = new_grid[new_row][new_col], new_grid[row][col]
                neighbors.append(PuzzleState(new_grid, self.g_cost + 1, self, move_name))
        
        return neighbors
    
    def __lt__(self, other):
        return False
    
    def __eq__(self, other):
        return self.grid == other.grid
    
    def __hash__(self):
        return hash(str(self.grid))

def solve_8_puzzle(initial, goal):
    initial_state = PuzzleState(initial)
    goal_state = PuzzleState(goal)
    
    heap = [(initial_state.f_cost(goal), initial_state)]
    visited = set()
    
    while heap:
        f_cost, current = heapq.heappop(heap)
        
        if current == goal_state:
            path = []
            while current:
                path.append(current)
                current = current.parent
            return path[::-1]
        
        if hash(current) in visited:
            continue
        visited.add(hash(current))
        
        for neighbor in current.get_neighbors():
            if hash(neighbor) not in visited:
                heapq.heappush(heap, (neighbor.f_cost(goal), neighbor))
    
    return None

def print_grid(grid):
    for row in grid:
        print(" ".join(row))
    print()

# Example usage
initial = [['2', '8', '3'], ['1', '6', '4'], ['7', '_', '5']]
goal = [['1', '2', '3'], ['8', '_', '4'], ['7', '6', '5']]

print("8-Puzzle Problem - A* Search")
print("Initial State:")
print_grid(initial)
print("Goal State:")
print_grid(goal)

solution = solve_8_puzzle(initial, goal)

if solution:
    print(f"Solution found in {len(solution)-1} moves:")
    for i, state in enumerate(solution):
        if i == 0:
            print("Initial:")
        else:
            print(f"Move {i}: {state.move}")
        print_grid(state.grid)
else:
    print("No solution found")