#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 3 // 3x3 Puzzle

// Goal state for comparison
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Structure to store each state of the puzzle
struct Node {
    vector<vector<int>> mat;
    int x, y;      // Blank tile coordinates
    int cost;      // Heuristic cost (f = g + h)
    int level;     // g(n) - Depth of the node in the tree
    string path;   // Path from initial to this node

    // Custom comparator for priority queue
    bool operator>(const Node& other) const {
        return (cost > other.cost);
    }
};

// Direction vectors for moving blank tile: up, down, left, right
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};
string dir[] = {"Down", "Up", "Left", "Right"};

// Check if (x, y) is within grid
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Calculate Manhattan distance as heuristic
int calculateHeuristic(const vector<vector<int>>& mat) {
    int dist = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] != 0) {
                int val = mat[i][j] - 1;
                int goalX = val / N;
                int goalY = val % N;
                dist += abs(i - goalX) + abs(j - goalY);
            }
    return dist;
}

// Convert board to string for hashing
string boardToString(const vector<vector<int>>& mat) {
    string s = "";
    for (auto row : mat)
        for (auto val : row)
            s += to_string(val);
    return s;
}

// A* Search Algorithm
void solvePuzzle(vector<vector<int>> initial, int x, int y) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    unordered_set<string> visited;

    Node root = {initial, x, y, 0, 0, ""};
    root.cost = calculateHeuristic(initial);
    pq.push(root);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        string boardStr = boardToString(current.mat);
        if (visited.find(boardStr) != visited.end())
            continue;

        visited.insert(boardStr);

        if (current.mat == goal) {
            cout << "Solved in " << current.level << " moves!\n";
            cout << "Path: " << current.path << endl;
            return;
        }

        // Try all possible directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + row[i];
            int newY = current.y + col[i];

            if (isSafe(newX, newY)) {
                Node child = current;
                swap(child.mat[current.x][current.y], child.mat[newX][newY]);
                child.x = newX;
                child.y = newY;
                child.level = current.level + 1;
                child.cost = child.level + calculateHeuristic(child.mat);
                child.path = current.path + dir[i] + " ";
                pq.push(child);
            }
        }
    }

    cout << "No solution found.\n";
}

// Driver code
int main() {
    vector<vector<int>> initial = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int x = 1, y = 2; // Position of blank tile (0)

    solvePuzzle(initial, x, y);

    return 0;
}
