// Given N strings and Q queries 
// In each query you are given a string 
// print frequence of that string 

// N <= 10^6
// |S| <= 100
// Q <= 10^6


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print(unordered_map<int,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &value : m)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}

// void print(map<string,string> &m)
// {
//     cout<<m.size()<<endl;
//     for(auto &value : m)
//     {
//         cout<<value.first<<" "<<value.second<<endl;
//     }
// }

int main()
{
    unordered_map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    // for(auto &value : m)
    // {
    //     cout<< value.first<<" "<<value.second<<endl;
    // }
    int q ;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<m[s]<<endl;
    }


    

    return 0;
}