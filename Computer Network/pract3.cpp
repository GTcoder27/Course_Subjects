#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Structure to represent a graph edge
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Structure to represent a node in the graph
struct Node {
    int id;
    vector<Edge> neighbors;
    Node(int i) : id(i) {}
};

// Dijkstra's algorithm function
void dijkstra(vector<Node>& graph, int source, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (distances[u] < dist_u)
            continue;

        for (const Edge& e : graph[u].neighbors) {
            int v = e.to;
            int weight = e.weight;
            if (dist_u + weight < distances[v]) {
                distances[v] = dist_u + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    // Example graph representation
    int n = 6; // Number of nodes
    vector<Node> graph(n, Node(-1));

    // Adding edges to the graph
    graph[0].neighbors.emplace_back(1, 5);
    graph[0].neighbors.emplace_back(2, 3);
    graph[1].neighbors.emplace_back(3, 6);
    graph[1].neighbors.emplace_back(4, 2);
    graph[2].neighbors.emplace_back(3, 2);
    graph[2].neighbors.emplace_back(4, 7);
    graph[3].neighbors.emplace_back(5, 4);
    graph[4].neighbors.emplace_back(5, 1);

    // Applying Dijkstra's algorithm
    vector<int> distances;
    dijkstra(graph, 0, distances);

    // Output shortest distances from source to all other nodes
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from node 0 to node " << i << " : " << distances[i] << endl;
    }

    return 0;
}



