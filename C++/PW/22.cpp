#include<bits/stdc++.h>
using namespace std;
// pascal triangle



int main()
{
    
    int n;
    cin>>n;
    int a[n][n];

    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            if(j == 0 || i==j){
                a[i][j] = 1;
                cout<<a[i][j]<<" ";
            }
            else{
                a[i][j] = a[i-1][j] + a[i-1][j-1];
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    





    return 0;
}
