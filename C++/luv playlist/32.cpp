#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    // vector<int> v = {10,20,30,40,50,60};
    // vector<int> v1 = {100,200,300,400,500,600};
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // vector<int>::iterator it ;
    // for(it=v.begin();it!=v.end();it++)
    // {
    //     cout<< (*it) <<" ";
    // }
    // cout<<endl;
    // for(int value : v)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;
    // for(int &value : v1)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;
    // vector<pair<int,int>> v_p = {{1,2},{3,4},{5,6}};
    // for(pair<int,int> &value : v_p)
    // {
    //     cout<<value.first<<" "<<value.second<<endl;
    // }
    // auto  a = 1;
    // cout<<a<<endl;




    vector<int> v = {10,20,30,40,50,60};
    vector<int> v1 = {100,200,300,400,500,600};
    cout<<endl;
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<< (*it) <<" ";
    }
    cout<<endl;
    for(auto value : v)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    for(auto &value : v1)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    vector<pair<int,int>> v_p = {{1,2},{3,4},{5,6}};
    for(auto &value : v_p)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }






    return 0;
}