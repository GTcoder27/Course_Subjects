#include<bits/stdc++.h>
using namespace std;
// sum of square matrix 

int main()
{
    
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(j==0) continue;
            v[i][j] += v[i][j-1];
        }
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sum = 0;
    for(int i=a;i<=c;i++){
        sum += v[i][d] - v[i][b-1];
    }
    cout<<sum<<endl;

    



    





    

    return 0;
}


// input 
// 3 4
// 1 2 3 4 5 6 7 8 9 10 11 12
