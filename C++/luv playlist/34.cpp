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
    unordered_map<int,string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    // m.insert({4,"afg"});
    print(m);

   

    

    






    return 0;
}