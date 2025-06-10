class TicTacToe:
    def __init__(self):
        self.board = [[' ' for _ in range(3)] for _ in range(3)]
        self.current_player = 'X'  # X starts first (Alex)
        
    def print_board(self):
        print("\n  0   1   2")
        for i in range(3):
            print(f"{i} {self.board[i][0]} | {self.board[i][1]} | {self.board[i][2]}")
            if i < 2:
                print("  ---------")
    
    def is_winner(self, board, player):
        # Check rows, columns, and diagonals
        for i in range(3):
            if all(board[i][j] == player for j in range(3)):  # Row
                return True
            if all(board[j][i] == player for j in range(3)):  # Column
                return True
        
        # Diagonals
        if all(board[i][i] == player for i in range(3)):
            return True
        if all(board[i][2-i] == player for i in range(3)):
            return True
        
        return False
    
    def is_board_full(self, board):
        return all(board[i][j] != ' ' for i in range(3) for j in range(3))
    
    def get_empty_cells(self, board):
        return [(i, j) for i in range(3) for j in range(3) if board[i][j] == ' ']
    
    def minimax(self, board, depth, is_maximizing, alpha=float('-inf'), beta=float('inf')):
        # Base cases
        if self.is_winner(board, 'X'):
            return 10 - depth
        if self.is_winner(board, 'O'):
            return depth - 10
        if self.is_board_full(board):
            return 0
        
        if is_maximizing:  # X's turn (maximize)
            max_eval = float('-inf')
            for row, col in self.get_empty_cells(board):
                board[row][col] = 'X'
                eval_score = self.minimax(board, depth + 1, False, alpha, beta)
                board[row][col] = ' '
                max_eval = max(max_eval, eval_score)
                alpha = max(alpha, eval_score)
                if beta <= alpha:
                    break
            return max_eval
        else:  # O's turn (minimize)
            min_eval = float('inf')
            for row, col in self.get_empty_cells(board):
                board[row][col] = 'O'
                eval_score = self.minimax(board, depth + 1, True, alpha, beta)
                board[row][col] = ' '
                min_eval = min(min_eval, eval_score)
                beta = min(beta, eval_score)
                if beta <= alpha:
                    break
            return min_eval
    
    def get_best_move(self, board, player):
        best_score = float('-inf') if player == 'X' else float('inf')
        best_move = None
        
        for row, col in self.get_empty_cells(board):
            board[row][col] = player
            score = self.minimax(board, 0, player == 'O')
            board[row][col] = ' '
            
            if player == 'X' and score > best_score:
                best_score = score
                best_move = (row, col)
            elif player == 'O' and score < best_score:
                best_score = score
                best_move = (row, col)
        
        return best_move
    
    def make_move(self, row, col, player):
        if self.board[row][col] == ' ':
            self.board[row][col] = player
            return True
        return False
    
    def play_game(self, mode='ai_vs_ai'):
        print("=== Tic-Tac-Toe Game ===")
        print("Alex (X) vs Sam (O)")
        print("Mode:", mode)
        
        while True:
            self.print_board()
            
            if self.is_winner(self.board, 'X'):
                print("\n🎉 Alex (X) wins!")
                break
            elif self.is_winner(self.board, 'O'):
                print("\n🎉 Sam (O) wins!")
                break
            elif self.is_board_full(self.board):
                print("\n🤝 It's a draw!")
                break
            
            print(f"\n{self.current_player}'s turn")
            
            if mode == 'ai_vs_ai' or (mode == 'human_vs_ai' and self.current_player == 'O'):
                # AI move using minimax
                row, col = self.get_best_move(self.board, self.current_player)
                self.make_move(row, col, self.current_player)
                print(f"AI plays at position ({row}, {col})")
            else:
                # Human move
                try:
                    row = int(input("Enter row (0-2): "))
                    col = int(input("Enter column (0-2): "))
                    if not self.make_move(row, col, self.current_player):
                        print("Invalid move! Cell already occupied.")
                        continue
                except (ValueError, IndexError):
                    print("Invalid input! Enter numbers 0-2.")
                    continue
            
            # Switch player
            self.current_player = 'O' if self.current_player == 'X' else 'X'

# Demo game
def demo_game():
    game = TicTacToe()
    
    # Set up a specific board state for demonstration
    moves = [(1, 1, 'X'), (0, 0, 'O'), (0, 2, 'X'), (2, 0, 'O')]
    
    print("Demo: Mid-game scenario")
    for row, col, player in moves:
        game.make_move(row, col, player)
    
    game.current_player = 'X'
    game.print_board()
    
    print(f"\nBest move for {game.current_player}:")
    best_move = game.get_best_move(game.board, game.current_player)
    print(f"Position: {best_move}")

# Run demo
demo_game()

# Uncomment to play full game
# game = TicTacToe()
# game.play_game('ai_vs_ai')  # or 'human_vs_ai'