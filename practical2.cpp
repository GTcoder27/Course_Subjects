#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MapColoring {
    vector<string> regions;
    unordered_map<string, vector<string>> neighbors;
    vector<string> colors;
    unordered_map<string, string> assignment;

public:
    MapColoring(vector<string> r, unordered_map<string, vector<string>> n, vector<string> c)
        : regions(r), neighbors(n), colors(c) {}

    bool is_valid(const string& region, const string& color) {
        for (const string& neighbor : neighbors[region]) {
            if (assignment.find(neighbor) != assignment.end() && assignment[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool backtrack(int region_index = 0) {
        if (region_index == regions.size()) {
            return true;
        }

        string region = regions[region_index];
        for (const string& color : colors) {
            if (is_valid(region, color)) {
                assignment[region] = color;
                if (backtrack(region_index + 1)) {
                    return true;
                }
                assignment.erase(region); // Undo assignment
            }
        }

        return false; // No valid color found
    }

    unordered_map<string, string> solve() {
        if (backtrack()) {
            return assignment;
        } else {
            return {}; // Empty map indicates failure
        }
    }
};

int main() {
    vector<string> regions = {"A", "B", "C", "D"};
    unordered_map<string, vector<string>> neighbors = {
        {"A", {"B", "C"}},
        {"B", {"A", "C", "D"}},
        {"C", {"A", "B", "D"}},
        {"D", {"B", "C"}}
    };
    vector<string> colors = {"Red", "Green", "Blue"};

    MapColoring solver(regions, neighbors, colors);
    unordered_map<string, string> solution = solver.solve();

    if (!solution.empty()) {
        cout << "Valid Coloring:\n";
        for (const auto& entry : solution) {
            cout << entry.first << ": " << entry.second << "\n";
        }
    } else {
        cout << "No valid coloring found.\n";
    }

    return 0;
} 
