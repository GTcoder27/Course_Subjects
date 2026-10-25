// More's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(11);
    nums.push_back(15);
    
    int ans = 0,freq = 0;
    for(int i=0;i<nums.size();i++){
        if(freq == 0) ans = nums[i];
        if(nums[i] == ans) freq++;
        if(nums[i] != ans) freq--;
    }
    cout<<ans;

    return 0;
}

