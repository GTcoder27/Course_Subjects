#include<bits/stdc++.h>
using namespace std;
// matrix sum 2nd approach O(n)

int main()
{
    // O(N)
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));

    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(j==0) continue;
                v[i][j] += v[i][j-1];
            }
        }
        else{
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(j==0){
                    v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + v[i][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sum = v[c][d] - v[c][b-1] - v[a-1][d] + v[a-1][b-1];

    cout<<sum<<endl;

    





    

    return 0;
}


// input 
// 3 4 
// 1 2 3 4 5 6 7 8 9 10 11 12
