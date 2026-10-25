#include<bits/stdc++.h>
using namespace std;
// Subset Generation

vector<vector<int> > subsets;

void generate(vector<int> &subset,int i,vector<int> &nums)
{
    if(i == nums.size()){
        subsets.push_back(subset);
        return;
    }
    // ith element not in subset
    generate(subset,i+1,nums);

    // ith element in subset
    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    subset.pop_back();
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> empty;
    
    generate(empty,0,nums);

    for(auto i:subsets){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}