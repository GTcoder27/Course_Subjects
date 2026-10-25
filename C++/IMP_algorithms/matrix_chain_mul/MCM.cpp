#include<bits/stdc++.h>
using namespace std;
// Matrix chain multiplication

int mcm(vector<int> &arr , int i, int j){   // without DP
    if(i == j) return 0; //single matrix case

    int ans = INT_MAX;
    for(int k=i; k <= j-1; k++) {
        int cost1 = mcm(arr, i, k); //Ai ... Ak => arr[i-1]xarr [k]
        int cost2 = mcm(arr, k+1, j); //Ai+1 ... Aj => arr[k]xarr[j]
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int finalCost = cost1 + cost2 + cost3;
        ans = min(ans, finalCost);
    }
    return ans; //mincost
}



int mcmdp(vector<int> &arr , int i, int j,vector<vector<int>> &dp){   // with DP
    if(i == j) return 0; //single matrix case
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k <= j-1; k++) {
        int cost1 = mcmdp(arr, i, k,dp); //Ai ... Ak => arr[i-1]xarr [k]
        int cost2 = mcmdp(arr, k+1, j,dp); //Ai+1 ... Aj => arr[k]xarr[j]
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int finalCost = cost1 + cost2 + cost3;
        ans = min(ans, finalCost);
    }
    return dp[i][j] = ans; //mincost
}


int main(){

    vector<int> arr = {1, 2, 3, 4, 3}; //n = 5
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    
    // cout<<mcm(arr,1, n-1);
    cout<<mcmdp(arr,1, n-1,dp);
}