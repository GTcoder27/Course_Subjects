#include<bits/stdc++.h>
using namespace std;
// Google interview question

const int N = 2e3+10;
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
    int n;
    cin>>n;
    vector<pair<int,int>> cities(n+1);

    for(int i=1;i<=n;i++){
        cin>>cities[i].first>>cities[i].second;
    }

    vector<int> c(n+1), k(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }

    vector<pair<long long, pair<int,int>>> edges;

    for(int i=1;i<=n;i++){
        edges.push_back({c[i],{0,i}});
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dist = abs(cities[i].first - cities[j].second)+abs(cities[i].second - cities[j].second);
            long long cost = dist * 1LL * (k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    long long total_cost = 0;
    vector<int> power_stations;
    vector<pair<int,int>> connections;
    for(auto &edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u,v);
        total_cost += wt;
        if(u==0 || v==0){
            power_stations.push_back(max(u,v));
        }
        else{
            connections.push_back({u,v});
        }
    }
    cout<<total_cost<<endl;
    cout<<power_stations.size()<<endl;
    for(int station:power_stations){
        cout<<station<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto &connection:connections){
        cout<<connection.first<<" "<<connection.second;
    }
    cout<<endl;
    

}


// input
// 3
// 2 3
// 1 1
// 3 2
// 3 2 3
// 3 2 3

// output
// 8
// 3
// 2 1 3 
// 0

