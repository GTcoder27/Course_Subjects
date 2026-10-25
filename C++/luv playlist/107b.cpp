#include<bits/stdc++.h>
using namespace std;
// leetcode Que no 518 Coin change 2

int dp[310][10010];


int func(int ind,int amount, vector<int> &coins){
    if(amount == 0) return 1;
    if(ind < 0 ) return 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int ways = 0;
    for(auto coin:coins){
        for(int coin_amount = 0;coin_amount <= amount;coin_amount+=coins[ind]){
            ways += func(ind-1,amount-coin_amount,coins);
        }
    }
    return dp[ind][amount] = ways;
}
 

int change(int amount, vector<int>& coins) {
    memset(dp,-1,sizeof(dp));
    int ans = func(amount,coins);
    return ans == INT_MAX ? -1 : ans;
}


int main()
{
    
     
}


// input
// 8
// 10 9 2 5 3 7 101 18