#include<bits/stdc++.h>
using namespace std;







int main()
{
    vector<int> v = {6,2,4,3,1};
    vector<int> v1 = {6,2,4,3,1};
    for(int i=1;i<v.size();i++){
        v[i] += v[i-1]; 
    }
    if(v[v.size()-1]%2 != 0) {
        cout<<"false";
        return 0;
    }
    int mid = -1;
    for(int i=0;i<v.size()-1;i++){
        if(v[i] == (v[(v.size()-1)]/2)){
            // cout<<v[i]<<endl<<v[(v.size()-1)]/2;
            mid = i;
        }
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
        if(i==mid) cout<<endl;
    }

    return 0;
}
