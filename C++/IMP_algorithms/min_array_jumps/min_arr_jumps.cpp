#include <bits/stdc++.h>
using namespace std;
// Minimum array jumps or  frog jump   


int maj(vector<int> &nums,vector<int> &dp){
    int n = nums.size();
    dp[n-1] = 0;

    for(int i=n-2; i>=0; i-- ) {
        int steps = nums[i];
        int ans = INT_MAX;
        for(int j=i+1; j <= i+steps && j<n; j++) {
            if(dp[j] != -1) {
                ans = min(ans, dp[j]+1);
            }
        }

        if(ans != INT_MAX) {
            dp[i] = ans;
        }
    }

    return dp[0];
}



int main(){

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    vector<int> dp(n+1,-1);

    cout<<maj(nums,dp);

    return 0;
}



// Input 
// 5
// 2 3 1 1 4

// output 
// 2