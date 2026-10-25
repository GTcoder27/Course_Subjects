#include<bits/stdc++.h>
using namespace std;
// Dijkstra Algorithm ( using priority queues)

const int INF = 1e9+10;


void dijkstra(int source,vector<vector<pair<int,int>>> &g,int nodes){
    vector<int> vis(nodes,0);
    vector<int> dist(nodes,INF);

    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> > pq; // {dist,vertex}  we can also use set here 

    pq.push({0,source});
    dist[source] = 0;

    while(pq.size() > 0){
        auto node = pq.top();
        int v = node.second;
        int v_dist = node.first;
        pq.pop();
        if(vis[v]) continue;   
        vis[v] = 1; 
        for(auto child:g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                pq.push({dist[child_v],child_v});
            }
        }
    }

    for(int i=1;i<nodes;i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }

}


int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<pair<int,int>>> g(nodes, vector<pair<int,int>> ()); // {vertex,dist}
    
    for(int i=0;i<edges;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    dijkstra(0,g,nodes);
    
    return 0;
}

// input 
// 6 8 
// 0 1 2
// 0 2 4
// 1 3 7
// 1 2 1
// 2 4 3
// 3 5 1
// 4 3 2
// 4 5 5


// expeccted output
// 0 -> 0 
// 1 -> 2
// 2 -> 3
// 3 -> 8
// 4 -> 6
// 5 -> 9










