#include<bits/stdc++.h>
using namespace std;
// Traveling Salesmen's problem

// not completed yet

int dist[N][N];

int main()
{   
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            int x,y,wt;
            cin>>x>>y>>wt;
            dist[x][y] = wt;

        }
    }
    

    return 0;
}


input
0 10 15 20
