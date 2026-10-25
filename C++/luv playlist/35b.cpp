// Given N strings, print unique strings in lexiographical order 
// N <= 10^5
// |S| <= 100000

#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int main()
{
    multiset<string> s;
    s.insert("abcd");
    s.insert("abcd");



    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     string str;
    //     cin>>str;
    //     s.insert(str);
    // }
    for(auto value : s)
    {
        cout<<value<<endl;
    }





    return 0;
}