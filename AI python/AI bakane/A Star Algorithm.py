import heapq

def manhattan(board):
    goal = ((1, 2, 3), (4, 5, 6), (7, 8, 0))  # Use 0 instead of '_'
    return sum(abs(i - (val - 1) // 3) + abs(j - (val - 1) % 3)
               for i, row in enumerate(board) for j, val in enumerate(row) if val != 0)

def get_moves(board):
    for i, row in enumerate(board):
        if 0 in row:
            x, y = i, row.index(0)
            break
    
    moves = []
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        new_x, new_y = x + dx, y + dy
        if 0 <= new_x < 3 and 0 <= new_y < 3:
            new_board = [list(row) for row in board]
            new_board[x][y], new_board[new_x][new_y] = new_board[new_x][new_y], 0
            moves.append((tuple(tuple(row) for row in new_board), (new_x, new_y)))
    return moves

def solve_puzzle(start):
    pq = [(manhattan(start), 0, start, [])]
    visited = set()
    while pq:
        _, moves, board, path = heapq.heappop(pq)
        if board == ((1, 2, 3), (4, 5, 6), (7, 8, 0)):
            return path + [board]
        visited.add(board)
        for new_board, _ in get_moves(board):
            if new_board not in visited:
                heapq.heappush(pq, (moves + manhattan(new_board), moves + 1, new_board, path + [board]))
    return None

def print_board(board):
    for row in board:
        print(" ".join(str(x) if x != 0 else '_' for x in row))  # Convert 0 back to '_'
    print()

def get_user_input():
    print("Enter the initial 3x3 puzzle state row by row, using '_' for the empty space:")
    board = []
    for _ in range(3):
        row = input().split()
        if len(row) != 3:
            print("Invalid row length! Please enter exactly 3 values.")
            return get_user_input()
        try:
            row = [int(x) if x != '_' else 0 for x in row]  # Convert '_' to 0
        except ValueError:
            print("Invalid input! Please enter numbers or '_'.")
            return get_user_input()
        board.append(tuple(row))
    return tuple(board)

# Get initial state from user
initial = get_user_input()
solution = solve_puzzle(initial)
if solution:
    print("Solution in", len(solution) - 1, "moves:")
    for step in solution:
        print_board(step)
else:
    print("No solution found!")
