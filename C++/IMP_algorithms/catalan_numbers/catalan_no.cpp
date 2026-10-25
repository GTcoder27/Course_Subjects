#include <bits/stdc++.h>
using namespace std;


int catalan_recursion(int n,vector<int> &dp){
    if(dp[n] != -1) return dp[n];
    if(n == 0 || n == 1) return dp[n] = 1;

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalan_recursion(n-i-1,dp)*catalan_recursion(i,dp);
    }
    return dp[n] = ans;
}

int catalan_tabulation(int n,vector<int> &dp){
    
    dp[0] = dp[1] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            dp[i] += dp[j] * dp[n-j-1];
        }
    }   


    return dp[n];
} 




int main(){

    int n;
    cin >> n;
    vector<int> dp(n+1,-1);

    // cout<<catalan_recursion(n,dp);

    cout<<catalan_tabulation(n,dp);

    return 0;
}


// input 
// 5

// output
// 52