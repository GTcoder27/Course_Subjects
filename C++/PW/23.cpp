#include<bits/stdc++.h>
using namespace std;
// rotate 90 degree 


void rotate(vector<vector<int>>& v,int n,int m){

    // transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    // reverse every row
    for(int i=0;i<n;i++){
        reverse(v[i].begin(),v[i].end());
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}




int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    rotate(v,n,m);
    

    

    





    return 0;
}
