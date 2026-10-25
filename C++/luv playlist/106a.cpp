#include<bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence
// leetcode question Q no. 300 

const int N = 25e2+10;
int dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j=0;j<i;j++){
        if(a[i] > a[j]){
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}


int lengthOfLIS(vector<int>& nums){
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans = max(ans,lis(i));
    }
    return ans;
}






// O(N^2)
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,lis(i));
    }
    cout<<ans<<endl;
}




// input
// 8
// 10 9 2 5 3 7 101 18