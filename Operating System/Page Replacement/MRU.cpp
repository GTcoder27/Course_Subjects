#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v1={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int f_size = 4;
    int mis=0, hit=0,last=0;
    vector<int> v2;
    for(int i=0;i<f_size;i++)
    {
        v2.push_back(v1[i]);
        mis++;
        cout<<"mis\t";
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=f_size;i<v1.size();i++){
        auto it = find(v2.begin(),v2.end(),v1[i]);
        if(it != v2.end()) {
            cout<<"hit\t";
            hit++;
            last = v1[i];
        }
        else{
            cout<<"mis\t";
            auto it = find(v2.begin(),v2.end(),last);
            v2[it-v2.begin()] = v1[i];
            mis++;
            last = v1[i];
        }
        for(auto j:v2) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit count = "<<hit<<endl;
    cout<<"Mis count = "<<mis<<endl;
    return 0;
}