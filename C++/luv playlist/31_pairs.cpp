#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // vector<int> v = {10,20,30,40,50,60};
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // vector<int>::iterator it = v.begin();
    // // cout<<(*(it+1))<<endl;
    // for(it=v.begin();it!=v.end();it++)
    // {
    //     cout<< (*it) <<endl;
    // }

    vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it;
    for (it = v_p.begin(); it != v_p.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    for (it = v_p.begin(); it != v_p.end(); it++)
    {
        cout << (it->first) << " " << (it->second) << endl;
    }

    return 0;
}