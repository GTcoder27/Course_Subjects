#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// Class representing the state of all items
class State {
public:
    int man, tiger, cow, grass;

    State(int man, int tiger, int cow, int grass)
        : man(man), tiger(tiger), cow(cow), grass(grass) {}

    // Check if the current state is safe
    bool is_safe() const {
        if ((cow == tiger) && (man != cow)) return false;
        if ((grass == cow) && (man != grass)) return false;
        return true;
    }

    // Check if two states are equal
    bool operator==(const State& other) const {
        return man == other.man &&
               tiger == other.tiger &&
               cow == other.cow &&
               grass == other.grass;
    }

    // Convert the state to string for printing
    string to_string() const {
        return "Man: " + string(man ? "Left" : "Right") + ", " +
               "Tiger: " + string(tiger ? "Left" : "Right") + ", " +
               "Cow: " + string(cow ? "Left" : "Right") + ", " +
               "Grass: " + string(grass ? "Left" : "Right");
    }
};

// Custom hash function for State to use in unordered_set
struct HashState {
    size_t operator()(const State& s) const {
        return hash<int>()(s.man * 8 + s.tiger * 4 + s.cow * 2 + s.grass);
    }
};

// DFS function to find a valid path
bool dfs(State state, vector<State>& path, unordered_set<State, HashState>& visited) {
    if (!state.is_safe() || visited.count(state)) return false;

    visited.insert(state);

    if (state.man == 0 && state.tiger == 0 && state.cow == 0 && state.grass == 0) {
        path.push_back(state);
        return true;
    }

    // Possible moves: (man, tiger, cow, grass)
    vector<vector<int>> moves = {
        {1, 0, 0, 0},  // Man alone
        {1, 1, 0, 0},  // Man with tiger
        {1, 0, 1, 0},  // Man with cow
        {1, 0, 0, 1}   // Man with grass
    };

    for (const auto& move : moves) {
        State new_state(
            1 - state.man,
            move[1] ? 1 - state.tiger : state.tiger,
            move[2] ? 1 - state.cow : state.cow,
            move[3] ? 1 - state.grass : state.grass
        );

        if (dfs(new_state, path, visited)) {
            path.push_back(state);
            return true;
        }
    }

    visited.erase(state);
    return false;
}

// Driver function
void solve() {
    State initial(1, 1, 1, 1);
    vector<State> path;
    unordered_set<State, HashState> visited;

    if (dfs(initial, path, visited)) {
        reverse(path.begin(), path.end());
        for (const auto& step : path) {
            cout << step.to_string() << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
}

int main() {
    solve();
    return 0;
} 
