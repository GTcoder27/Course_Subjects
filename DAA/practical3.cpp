#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> State;

vector<State> waterJugBFS(int capacity1, int capacity2, int target) {
    queue<State> q;
    set<State> visited;
    map<State, State> parent;

    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int jug1 = current.first;
        int jug2 = current.second;

        if (jug1 == target || jug2 == target) {
            vector<State> path;
            while (current != State(0, 0)) {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back({0, 0});
            reverse(path.begin(), path.end());
            return path;
        }

        vector<State> nextStates = {
            {capacity1, jug2},                    // Fill Jug1
            {jug1, capacity2},                    // Fill Jug2
            {0, jug2},                            // Empty Jug1
            {jug1, 0},                            // Empty Jug2
            {jug1 - min(jug1, capacity2 - jug2), jug2 + min(jug1, capacity2 - jug2)}, // Pour Jug1 -> Jug2
            {jug1 + min(jug2, capacity1 - jug1), jug2 - min(jug2, capacity1 - jug1)}  // Pour Jug2 -> Jug1
        };

        for (State next : nextStates) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                parent[next] = current;
                q.push(next);
            }
        }
    }

    return {}; // No solution
}

void printSolution(const vector<State>& path) {
    if (!path.empty()) {
        cout << "Solution path:\n";
        for (auto& state : path) {
            cout << "Jug1: " << state.first << "L, Jug2: " << state.second << "L\n";
        }
    } else {
        cout << "No solution exists.\n";
    }
}

int main() {
    int capacity1 = 4;
    int capacity2 = 3;
    int target = 2;

    vector<State> solution = waterJugBFS(capacity1, capacity2, target);
    printSolution(solution);

    return 0;
}
