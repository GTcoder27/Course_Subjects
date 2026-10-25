// Kadan's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(-4);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(-8);
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i=0;i<nums.size();i++){
        curr_sum += nums[i];
        max_sum = max(max_sum,curr_sum);
        if(curr_sum < 0) curr_sum = 0;
    }
    cout<<max_sum;
    






    return 0;
}


