// Given N strings and q queries 
// In each query you are given a string 
// print yes if string is present 
// else print NO

#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int main()
{
    unordered_set<string> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.insert(str);
    }
    cout<<"these are strings"<<endl;
    for(auto value : s)
    {
        cout<<value<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        if(s.find(str) == s.end())
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }





    return 0;
}