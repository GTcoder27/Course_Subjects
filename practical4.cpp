#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N, vector<vector<vector<int>>>& solutions) {
    if (row == N) {
        solutions.push_back(board); // Save current solution
        return true;
    }

    bool res = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place queen

            res = solveNQueensUtil(board, row + 1, N, solutions) || res;

            board[row][col] = 0;  // Backtrack
        }
    }

    return res;
}

vector<vector<vector<int>>> solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> solutions;

    solveNQueensUtil(board, 0, N, solutions);
    return solutions;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the value of N for N-Queens: ";
    cin >> N;

    auto solutions = solveNQueens(N);

    if (!solutions.empty()) {
        cout << "Found " << solutions.size() << " solutions:\n";
        for (size_t i = 0; i < solutions.size(); i++) {
            cout << "Solution " << i + 1 << ":\n";
            printBoard(solutions[i]);
        }
    } else {
        cout << "No solutions found.\n";
    }

    return 0;
}
