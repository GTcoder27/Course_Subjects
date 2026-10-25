#include<bits/stdc++.h>
using namespace std;

// To find total no. of connected components in graphs 

const int N = 1e5+10;

vector<vector<int>> cc;
vector<int> current_cc;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    // cout<<vertex<<" ";
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}


int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        count++;
    }
    cout<<endl<<cc.size()<<endl;
    for(auto i:cc){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}



// input = 
// 8 5
// 1 2 
// 2 3
// 2 4
// 3 5
// 6 7









