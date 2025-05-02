#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 4;
const char PIT = 'P';
const char WUMPUS = 'W';
const char GOLD = 'G';
const char AGENT = 'A';
const char EMPTY = '.';
const char BREEZE = 'B';
const char STENCH = 'S';

typedef vector<vector<char>> Grid;

pair<int, int> agentPos = {0, 0};

// Function to display the grid (agent position only)
void displayGrid(const Grid &grid, pair<int, int> agentPos) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (agentPos.first == i && agentPos.second == j)
                cout << AGENT << ' ';
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to add breeze and stench in adjacent cells
void addPercepts(Grid &grid, int i, int j, char percept) {
    if (i > 0 && grid[i - 1][j] == EMPTY) grid[i - 1][j] = percept;
    if (i < SIZE - 1 && grid[i + 1][j] == EMPTY) grid[i + 1][j] = percept;
    if (j > 0 && grid[i][j - 1] == EMPTY) grid[i][j - 1] = percept;
    if (j < SIZE - 1 && grid[i][j + 1] == EMPTY) grid[i][j + 1] = percept;
}

Grid createGrid() {
    Grid grid(SIZE, vector<char>(SIZE, EMPTY));
    srand(time(0));

    // Add pits
    int pitCount = rand() % 3 + 3;
    for (int i = 0; i < pitCount; ) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if ((x != 0 || y != 0) && grid[x][y] == EMPTY) {
            grid[x][y] = PIT;
            i++;
        }
    }

    // Add Wumpus
    while (true) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if ((x != 0 || y != 0) && grid[x][y] == EMPTY) {
            grid[x][y] = WUMPUS;
            break;
        }
    }

    // Add Gold
    while (true) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if ((x != 0 || y != 0) && grid[x][y] == EMPTY) {
            grid[x][y] = GOLD;
            break;
        }
    }

    // Add Breezes and Stenches
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == PIT) addPercepts(grid, i, j, BREEZE);
            if (grid[i][j] == WUMPUS) addPercepts(grid, i, j, STENCH);
        }
    }

    return grid;
}

vector<string> getPercepts(pair<int, int> pos, Grid &grid) {
    vector<string> percepts;
    int x = pos.first, y = pos.second;

    if ((x > 0 && grid[x - 1][y] == PIT) ||
        (x < SIZE - 1 && grid[x + 1][y] == PIT) ||
        (y > 0 && grid[x][y - 1] == PIT) ||
        (y < SIZE - 1 && grid[x][y + 1] == PIT)) {
        percepts.push_back("Breeze");
    }

    if ((x > 0 && grid[x - 1][y] == WUMPUS) ||
        (x < SIZE - 1 && grid[x + 1][y] == WUMPUS) ||
        (y > 0 && grid[x][y - 1] == WUMPUS) ||
        (y < SIZE - 1 && grid[x][y + 1] == WUMPUS)) {
        percepts.push_back("Stench");
    }

    if (grid[x][y] == GOLD)
        percepts.push_back("Glitter");

    return percepts;
}

void playGame() {
    Grid grid = createGrid();
    pair<int, int> pos = {0, 0};

    cout << "Welcome to Wumpus World!" << endl;
    displayGrid(grid, pos);

    while (true) {
        vector<string> percepts = getPercepts(pos, grid);
        cout << "Percepts: ";
        for (auto &p : percepts) cout << p << " ";
        cout << endl;

        cout << "Move (up/down/left/right): ";
        string move;
        cin >> move;

        int x = pos.first, y = pos.second;

        if (move == "up" && x > 0) x--;
        else if (move == "down" && x < SIZE - 1) x++;
        else if (move == "left" && y > 0) y--;
        else if (move == "right" && y < SIZE - 1) y++;
        else {
            cout << "Invalid move!" << endl;
            continue;
        }

        pos = {x, y};
        displayGrid(grid, pos);

        char cell = grid[x][y];
        if (cell == PIT) {
            cout << "Agent fell into a pit. Game over!" << endl;
            break;
        }
        else if (cell == WUMPUS) {
            cout << "Agent was eaten by the Wumpus. Game over!" << endl;
            break;
        }
        else if (cell == GOLD) {
            cout << "Agent found the gold! You win!" << endl;
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}
