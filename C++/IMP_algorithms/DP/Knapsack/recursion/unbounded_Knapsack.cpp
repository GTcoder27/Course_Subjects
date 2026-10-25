#include<bits/stdc++.h>
using namespace std;
// Unbounded knapsack problem 



int knapsack(vector<int> &val,vector<int> &weight,int i,int capacity,vector<vector<int>> &dp){
    if(i == val.size() || capacity == 0) return 0;
    if(dp[i][capacity] != -1) return dp[i][capacity];

    if(weight[i] <= capacity){
        int temp1 = val[i] + knapsack(val,weight,i,capacity-weight[i],dp);  // with including
        int temp2 = knapsack(val,weight,i+1,capacity,dp);  // without including
        return dp[i][capacity] = max(temp1,temp2);
    }
    else{
        return dp[i][capacity] = knapsack(val,weight,i+1,capacity,dp); 
    }
}


int main(){

    int n;
    cin>>n;
    vector<int> val(n),weight(n);
    for(int i=0;i<n;i++){
        cin>>val[i]>>weight[i];
    }
    int capacity;
    cin>>capacity;
    vector<vector<int>> dp(n+1,vector<int> (capacity+1,-1));
    cout<<knapsack(val,weight,0,capacity,dp)<<endl;


    return 0;
}


// input 
// 5
// 15 2
// 14 5
// 10 1
// 45 3
// 30 4
// 7

// output
// 75




// fractional knapsack
// 0-1 Knapsack
// Unbounded Knapsack



