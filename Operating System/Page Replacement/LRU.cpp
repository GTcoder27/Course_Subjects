#include <bits/stdc++.h>
// some error is there in functio find_last()
using namespace std;
int find_last(vector<int> temp,vector<int> v1)
{
    int max_i = -1,max_e = 0;
    for(int i=0;i<v1.size();i++)
    {
        auto it = find(temp.begin(),temp.end(),v1[i]);
        if(max_i<(it-temp.begin())){
            max_i = it-temp.begin();
            max_e = temp[it-temp.begin()];
            cout<<max_i<<" "<<max_e<<endl;
        }
    }
    auto it1 = find(v1.begin(),v1.end(),max_e);
    return it1-v1.begin();
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
            for(int j=i-1;j>=0;j--){
                temp.push_back(v1[j]);
            }
            cout<<endl;
            for(auto k:temp){
                cout<<k<<" ";
            }
            cout<<endl;
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