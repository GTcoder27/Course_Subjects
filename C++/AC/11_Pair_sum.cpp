// Pair Sum
// two poiner approach

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 18;
    int l = 0, r = nums.size()-1;
    while(l<r){
        if(nums[l]+nums[r] == target){
            cout<<nums[l]<<" "<<nums[r]<<endl;
            return 0;
        }
        else if(nums[l]+nums[r] < target){
            l++;
        }
        else if(nums[l]+nums[r] > target){
            r--;
        }
    }
    cout<<"No pair found for target sum";

    return 0;
}

