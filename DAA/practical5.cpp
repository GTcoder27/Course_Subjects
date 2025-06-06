#include <bits/stdc++.h>

using namespace std;

using Board = vector<vector<string>>;

// Goal state
const Board GOAL = {
    {"1", "2", "3"},
    {"4", "5", "6"},
    {"7", "8", "_"}};

// Directions for blank tile: up, down, left, right
const vector<pair<int, int>> DIRECTIONS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Positions of goal tiles for Manhattan Distance
map<string, pair<int, int>> goalPos = {
    {"1", {0, 0}}, {"2", {0, 1}}, {"3", {0, 2}}, {"4", {1, 0}}, {"5", {1, 1}}, {"6", {1, 2}}, {"7", {2, 0}}, {"8", {2, 1}}, {"_", {2, 2}}};

// Converts board to string for hashing
string boardToString(const Board &b)
{
    string res;
    for (auto &row : b)
        for (auto &tile : row)
            res += tile;
    return res;
}

// Finds the position of blank tile
pair<int, int> findBlank(const Board &board)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == "_")
                return {i, j};
    return {-1, -1};
}

// Manhattan distance heuristic
int manhattanDistance(const Board &board)
{
    int dist = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != "_")
            {
                pair<int, int> pos = goalPos[board[i][j]];
                dist += abs(i - pos.first) + abs(j - pos.second);
            }
    return dist;
}

// State structure for priority queue
struct State
{
    Board board;
    int g; // Cost so far
    int h; // Heuristic
    vector<Board> path;

    int f() const { return g + h; }

    bool operator>(const State &other) const
    {
        return f() > other.f();
    }
};

// Get all valid neighbor boards by moving blank tile
vector<Board> getNeighbors(const Board &board)
{
    vector<Board> neighbors;
    pair<int, int> blank = findBlank(board);
    int x = blank.first;
    int y = blank.second;

    for (size_t k = 0; k < DIRECTIONS.size(); ++k)
    {
        int dx = DIRECTIONS[k].first;
        int dy = DIRECTIONS[k].second;

        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
        {
            Board newBoard = board;
            swap(newBoard[x][y], newBoard[nx][ny]);
            neighbors.push_back(newBoard);
        }
    }
    return neighbors;
}

// A* search algorithm
vector<Board> aStar(const Board &start)
{
    set<string> visited;
    priority_queue<State, vector<State>, greater<State>> pq;

    int h = manhattanDistance(start);
    pq.push({start, 0, h, {}});

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();
        string key = boardToString(current.board);

        if (visited.count(key))
            continue;
        visited.insert(key);

        if (current.board == GOAL)
        {
            current.path.push_back(current.board);
            return current.path;
        }

        for (auto &neighbor : getNeighbors(current.board))
        {
            string nkey = boardToString(neighbor);
            if (!visited.count(nkey))
            {
                int g = current.g + 1;
                int h = manhattanDistance(neighbor);
                auto newPath = current.path;
                newPath.push_back(current.board);
                pq.push({neighbor, g, h, newPath});
            }
        }
    }

    return {}; // No solution found
}

// Print board state
void printBoard(const Board &b)
{
    for (auto &row : b)
    {
        for (auto &tile : row)
            cout << tile << " ";
        cout << "\n";
    }
    cout << "\n";
}

// Input the initial board from user
Board getInputBoard()
{
    Board board(3, vector<string>(3));
    cout << "Enter the initial 3x3 board row by row (use '_' for blank):\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];
    }
    return board;
}

// Main function
int main()
{
    Board start = getInputBoard();
    cout << "\nInitial State:\n";
    printBoard(start);

    vector<Board> solution = aStar(start);

    if (!solution.empty())
    {
        cout << "Solution found in " << solution.size() - 1 << " moves:\n\n";
        for (auto &step : solution)
            printBoard(step);
    }
    else
    {
        cout << "No solution found!\n";
    }

    return 0;
}
