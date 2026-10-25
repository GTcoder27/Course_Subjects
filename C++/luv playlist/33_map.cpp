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
void print(map<string,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &value : m)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}

int main()
{
    map<int,string> m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4,"afg"});
    or
    m.insert(make_pair(4,"afg"));

    map<int,string> :: iterator it;
    for(it = m.begin();it != m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    print(m);
    // m.erase(5);
    auto it = m.find(3);
    if(it != m.end())
    {
        m.erase(it);
    }

    // if(it == m.end())
    // {
    //     cout<<"Value Not Found"<<endl;
    // }
    // else
    // {
    //     cout<<"Value found: "<<(*it).first<<" "<<(*it).second<<endl;
    // }

    // m.clear();
    // print(m);


    map<int,string> m;
    m[2] = "abcd";
    cout<<m[2][0];

    string s = "e";
    s.push_back('e');
    cout<<s<<endl;;
    s.pop_back();
    cout<<s<<endl;;







    return 0;
}