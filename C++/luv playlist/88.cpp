#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];

/* given q queries ,q <= 10^5
    In each query given V,
    print subtree sum of V & number of even numbers
    in subtree of V

*/

int subtree_sum[N];
int even_ct[N];

void dfs(int vertex,int par=0){

    if(vertex % 2 == 0){
        even_ct[vertex]++;
    }
    subtree_sum[vertex] += vertex; // because value of every vertex is that node only.
    for(int child : g[vertex]){
        
        if(child == par) continue;
        dfs(child,vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];

    }
    /* Take action on vertex before exiting the vertex */
}




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);

    for(int i=0;i<=n;i++){
        cout<<subtree_sum[i]<<" "<<even_ct[i]<<endl;
    }

    // int q;
    // while(q--){
    //     int v;
    //     cin>>v;
    //     cout<<subtree_sum[v]<<" "<<even_ct[v];

    // }
    

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








