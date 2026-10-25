#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N];
int hsh[N];
main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        hsh[i] = hsh[i-1] + arr[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<hsh[b]-hsh[a-1]<<endl;
    }






}