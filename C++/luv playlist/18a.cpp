#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
const int N = 1e7+10;
int hsh[N];
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        hsh[a[i]] += 1;  
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<hsh[x];
    }





    return 0;
}