#include<bits/stdc++.h>
using namespace std;
// Bellman Ford Algorithm

const int INF = 1e9+10;

void bellmanFord(int source, vector<vector<pair<int, int>>> &g, int nodes, int edges) {
    vector<int> dist(nodes, INF);
    dist[source] = 0;
    
    // Relax all edges (V-1) times
    for (int i = 0; i < nodes - 1; i++) {
        for (int u = 0; u < nodes; u++) {
            for (auto &edge : g[u]) {
                int v = edge.first;
                int wt = edge.second;
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    
    // Check for negative weight cycles
    for (int u = 0; u < nodes; u++) {
        for (auto &edge : g[u]) {
            int v = edge.first;
            int wt = edge.second;
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }
    }
    
    // Print shortest distances
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> g(nodes);
    
    for (int i = 0; i < edges; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    
    bellmanFord(0, g, nodes, edges);
    return 0;
}


// input 
// 5 6 
// 0 1 2 
// 0 2 4
// 1 2 -4
// 2 3 2
// 3 4 4
// 4 1 -1



// expeccted output
// 0 -> 0 
// 1 -> 2
// 2 -> -2
// 3 -> 0
// 4 -> 4


