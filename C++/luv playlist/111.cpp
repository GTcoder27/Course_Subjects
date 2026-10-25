#include<bits/stdc++.h>
using namespace std;
// Leetcode Que. 416 Partition equal subset sum 

const int N = 1e5+10;

int dp[210][20010];

int func(int ind,int sum,vector<int>& nums){
    if(sum == 0) return true;
    if(ind < 0) return false;
    if(dp[ind][sum] != -1) return dp[ind][sum]; 

    // not consider
    bool isPossible = func(ind-1,sum,nums);
    // consider
    isPossible = isPossible | func(ind-1,sum-nums[ind],nums);

    return dp[ind][sum] = isPossible;
}


bool canPartition(vector<int>& nums) {
    memset(dp,-1,sizeof(dp));
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum % 2 != 0) return false;
    sum = sum / 2;

    return func(nums.size()-1,sum,nums);
}



int main()
{
    
    

}


// input
