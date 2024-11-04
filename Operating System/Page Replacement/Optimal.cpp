#include <bits/stdc++.h>
using namespace std;
int find_last(vector<int> temp,vector<int> v1)
{
    for(int i=temp.size()-1;i>=0;i--)
    {
        auto it = find(v1.begin(),v1.end(),temp[i]);
        return it-v1.begin();
    }
    return 0;
}

int main()
{
    vector<int> v1={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    vector<int> temp;
    int f_size = 4;
    int mis=0, hit=0;
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
            for(int j=i+1;j<v1.size();j++){
                temp.push_back(v1[j]);
            }
            int last_e_i = find_last(temp,v1);
            v2[last_e_i] = v1[i];
            mis++;
            temp.clear();
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