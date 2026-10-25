#include<bits/stdc++.h>
using namespace std;
// Lowest Common Ancester

const int N = 1e5+10;
vector<int> g[N];
int par[N];


void dfs(int vertex,int p=-1){
    par[vertex] = p;
    for(int child : g[vertex]){ 
        if(child == p) continue;
        dfs(child,vertex);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    
    int x,y,lca;
    cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    for(int i=0;i<path_x.size();i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca;




    return 0;
}

// input 
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12 
// 4 9
// 4 10
// 10 11









