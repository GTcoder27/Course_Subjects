#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i == n){
            for(int j=1;j<=n;j++){
                cout<<i<<" ";
            }
            break;
        }
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        if(i==1) {
            cout<<i<<endl;
            continue;
        }
        cout<<i;
        for(int j=2;j<i*2;j++){
            cout<<" ";
        }
        cout<<i;
        

        cout<<endl;
    }




}
