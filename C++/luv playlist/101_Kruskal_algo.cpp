#include<bits/stdc++.h>
using namespace std;
// Kruskal's Algorithm Minimum spanning tree
// spanning mean connected i.e only one tree

const int N = 1e5+10;
int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]); 
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]){  // Union by size
            swap(a,b);
        }
        parent[b] = a; 
        size[a] += size[b];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    int total_cost = 0;
    for(auto &edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u,v);
        total_cost += wt;
        cout<<u<<" "<<v<<endl; 
    }
    cout<<total_cost<<endl;

}


// input
// 6 9
// 5 4 9
// 1 4 1
// 5 1 4
// 4 3 5
// 4 2 3
// 1 2 2
// 3 2 3
// 3 6 8
// 2 6 7

// output
// 2

// 9 14
// 1 2 10
// 1 3 12
// 2 3 9
// 2 4 8
// 4 5 7
// 3 5 3
// 3 6 1
// 5 6 3
// 6 8 6
// 4 8 5
// 4 7 8
// 7 8 9 
// 8 9 11
// 7 9 2

// output
// 43




