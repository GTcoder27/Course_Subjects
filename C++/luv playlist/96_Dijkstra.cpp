#include<bits/stdc++.h>
using namespace std;
// Dijkstra Algorithm

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N]; // {vertex,dist}

void dijkstra(int source){
    vector<int> vis(N,0);
    vector<int> dist(N,INF);

    set<pair<int,int>> st; // {dist,vertex}  in place of set we can also use priority queues 

    st.insert({0,source});
    dist[source] = 0;

    while(st.size() > 0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1; 
        for(auto child:g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }

    for(int i=1;i<7;i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }

}


int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    dijkstra(1);
    
    return 0;
}

// input 
// 2 1 1


// expeccted output
// 1 : 0
// 2 : 1
// 2 : 1
// 3 : 3
// 4 : 3
// 5 : 2
// 6 : 4










