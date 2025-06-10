def ConstBoard(board):
    print("Current State Of Board:\n")
    for i in range(9):
        if i > 0 and i % 3 == 0:
            print("\n")
        if board[i] == 0:
            print("-", end=" ")
        elif board[i] == 1:
            print("O", end=" ")
        else:
            print("X", end=" ")
    print("\n")

def UserTurn(board):
    pos = int(input("Enter X's position from [1...9]: "))
    if board[pos - 1] != 0:
        print("Wrong Move!!!")
        exit(0)
    board[pos - 1] = -1

def minimax(board, player):
    x = analyzeboard(board)
    if x != 0:
        return x * player

    pos = -1
    value = -2
    for i in range(9):
        if board[i] == 0:
            board[i] = player
            score = -minimax(board, -player)
            board[i] = 0
            if score > value:
                value = score
                pos = i
    if pos == -1:
        return 0
    return value

def CompTurn(board):
    pos = -1
    value = -2
    for i in range(9):
        if board[i] == 0:
            board[i] = 1
            score = -minimax(board, -1)
            board[i] = 0
            if score > value:
                value = score
                pos = i
    board[pos] = 1

def analyzeboard(board):
    win_conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6]
    ]
    for condition in win_conditions:
        if board[condition[0]] != 0 and board[condition[0]] == board[condition[1]] == board[condition[2]]:
            return board[condition[2]]
    return 0

def main():
    print("ALEX: O Vs. SAM: X")
    player = int(input("Enter to play 1(st) or 2(nd): "))
    board = [0] * 9

    for i in range(9):
        if analyzeboard(board) != 0:
            break
        if (i + player) % 2 == 0:
            CompTurn(board)
        else:
            ConstBoard(board)
            UserTurn(board)

    x = analyzeboard(board)
    ConstBoard(board)
    if x == 0:
        print("Draw!!!")
    elif x == -1:
        print("X Wins!!!")
    elif x == 1:
        print("O Wins!!!")

if __name__ == "__main__":
    main()
