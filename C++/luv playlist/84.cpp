#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    /* Take action on vertex after entering the vertex */
    for(int child : g[vertex]){
        /* Take action on child before entering the child node */
        dfs(child);
        /* Take action on child after exiting child node */
    }
    /* Take action on vertex before exiting the vertex */
}
void dfs(int vertex){
    cout<<vertex<<" ";
    vis[vertex] = true;
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

//  O(V+E)  V->vertices   E->edges
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    

    return 0;
}



// input = 
// 6 9
// 1 3 
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6








