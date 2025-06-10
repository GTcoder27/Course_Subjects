# Function to check if a queen can be placed at board[row][col]
def is_safe(board, row, col, n):
    # Check the entire row to the left (no two queens should be in the same row)
    for i in range(col):
        if board[row][i] == 1:
            return False  # Queen already present in the row

    # Check upper-left diagonal (diagonal going upwards left)
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False  # Queen found on upper diagonal

    # Check lower-left diagonal (diagonal going downwards left)
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False  # Queen found on lower diagonal

    return True  # Safe position for queen placement


# Recursive function to place queens column by column
def solve_n_queens_util(board, col, n):
    # Base Case: If all queens are placed successfully, return True
    if col >= n:
        return True  

    # Try placing the queen in each row of the current column
    for i in range(n):  
        if is_safe(board, i, col, n):  # Check if it's safe to place a queen here
            board[i][col] = 1  # Place the queen

            # Recursively attempt to place the next queen in the next column
            if solve_n_queens_util(board, col + 1, n):
                return True  # If successful, return True

            # If placing queen here doesn't work, backtrack and remove the queen
            board[i][col] = 0  

    return False  # If no row is valid for this column, return False (backtrack)


# Function to initialize the board and start solving the problem
def solve_n_queens(n):
    # Create an empty chessboard of size n × n (filled with 0s)
    board = [[0 for _ in range(n)] for _ in range(n)]

    # Start solving the problem from the first column (column index 0)
    if not solve_n_queens_util(board, 0, n):
        print("Solution does not exist")  # If no solution exists, print message
        return False  

    print_solution(board)  # Print the board if a solution is found
    return True


# Function to display the chessboard with queens placed
def print_solution(board):
    for row in board:
        # Replace '1' with 'Q' (Queen) and '0' with '.' (Empty space)
        print(" ".join('Q' if x == 1 else '.' for x in row))
    print()  # Print a blank line for clarity


# Take user input for the board size and solve the N-Queens problem
n = int(input("Enter board size: "))  # Ask the user for the board size (N)
solve_n_queens(n)  # Call the function to solve the problem
