#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hsh[N];
int main()
{   
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        hsh[arr[i]]++;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int no;
        cin>>no;
        cout<<hsh[no]<<endl;
    }
    return 0;
}