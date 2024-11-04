#include<bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int> v2 = {72,160,33,130,14,6,180};
    vector<int> v;
    int ans = 0,hp = 50,total = 0;
    int curr = hp;
    cout<<"Seek operations sequence : \n";
    v.push_back(hp);
    for(int j=0;j<v2.size();j++){
        int min_i,min_d = INT_MAX;
        for(int i=0;i<v2.size();i++)
        {
            auto it = find(v.begin(),v.end(),v2[i]);
            if(it == v.end())
            {
                if(min_d > abs(curr-v2[i]) && abs(curr-v2[i]) != 0){
                    min_d = abs(curr-v2[i]);
                    min_i = i;
                }
            }
        }
        v.push_back(v2[min_i]);
        cout<<v2[min_i]<<endl;
        curr = v2[min_i];
    }
    for(int i=1;i<v.size();i++)
    { 
        total += abs(v[i] - v[i-1]); 
    }
    cout<<"Total No of seek movement : "<<total;

return 0;
}