#include<bits/stdc++.h>
using namespace std;





int main()
{
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int ans[c][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans[j][i] = a[i][j]; 
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
