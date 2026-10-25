// Given N strings , print unique strings in  Lexographical order with their frequency
// N <= 10^5
// |S| <= 100


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// void print(map<int,string> &m)
// {
//     cout<<m.size()<<endl;
//     for(auto &value : m)
//     {
//         cout<<value.first<<" "<<value.second<<endl;
//     }
// }

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
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    for(auto &value : m)
    {
        cout<< value.first<<" "<<value.second<<endl;
    }


    return 0;
}