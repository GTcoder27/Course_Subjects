#include<bits/stdc++.h>
using namespace std;
// Edge deletion 



const int M = 1e9+7;
const int N = 1e5+10;
vector<int> g[N];
int subtree_sum[N];
int val[N];

void dfs(int vertex,int p=-1){
    
    subtree_sum[vertex] += val[vertex];
    for(int child : g[vertex]){ 

        if(child == p) continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];
    }
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
    dfs(1,0);
    long long ans = 0;
    for(int i=2;<=n;i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1]-part1;
        ans = max(ans,(part1*1LL*part1)%M);
    }
    cout<<ans;
    
    




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









