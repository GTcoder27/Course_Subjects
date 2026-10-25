#include<bits/stdc++.h>
using namespace std;







main()
{
    vector<int> v = {-10,-3,2,4,5};
    vector<int> ans;
    int left_p = 0;
    int right_p = v.size()-1;


    while(left_p<right_p){

        if(abs(v[left_p]) <= abs(v[right_p])){
            ans.push_back(pow(v[left_p++],2));
        }
        if(abs(v[left_p]) >= abs(v[right_p])){
            ans.push_back(pow(v[right_p++],2));
        }

    }
    for(int i:ans){
        cout<<i<<" ";
    }


}
