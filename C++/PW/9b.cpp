#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch = 'A';
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int j=1;j<=(i*2)-1;j++){
            cout<<ch++;
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        char ch = 'A';
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int j=1;j<=(i*2)-1;j++){
            cout<<ch++;
        }
        cout<<endl;
    }


}
