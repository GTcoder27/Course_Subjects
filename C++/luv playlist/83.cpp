#include<bits/stdc++.h>
using namespace std;

// representation of graphs -> 1] Adjacency Matrix 
//                             2] Adjacency List 

const int N = 1e3+10;
int graph1[N][N];

// vector<int> graph2[N];

vector<pair<int,int>> graph2[N];


int main()
{
    int n,m;
    cin>>n>>m;
    // for(int i=0;i<m;i++){
    //     int v1,v2;
    //     cin>>v1>>v2;
    //     graph1[v1][v2] = 1;
    //     graph1[v1][v2] = 1;

    //     graph2[v1].push_back(v2);
    //     graph2[v2].push_back(v1);
    // }

    for(int i=0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2;
        graph1[v1][v2] = wt;
        graph1[v1][v2] = wt;

        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }



    for(int i=0;i<20;i++){
        cout<<i<<" = ";
        for(auto j:g[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }



    return 0;
}











