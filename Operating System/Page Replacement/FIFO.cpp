#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v1={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int f_size = 3;
    int mis=0, hit=0,temp_i=0;
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
        }
        else{
            cout<<"mis\t";
            v2[(temp_i++)%3] = v1[i];
            mis++;
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