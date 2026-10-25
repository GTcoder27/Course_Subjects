#include<bits/stdc++.h>
using namespace std;
// Unbounded knapsack problem 



int knapsack(vector<int> &val,vector<int> &weight,int capacity,vector<vector<int>> &dp){
    int n = val.size();

    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<capacity+1;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<n+1;i++){  // i means index of val or weight 
        for(int cap=1;cap<capacity+1;cap++){  // capacity of bag
            if(weight[i-1] <= cap){
                dp[i][cap] = max((val[i-1] + dp[i-1][cap-weight[i-1]]) , (dp[i-1][cap]));  // max(by including , by not including)
            }
            else{
                dp[i][cap] = dp[i-1][cap];  // by not including
            }
        }
    }

    return dp[n][capacity];
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
    vector<vector<int>> dp(n+1,vector<int> (capacity+1));
    cout<<knapsack(val,weight,capacity,dp)<<endl;

    for(auto i:dp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

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

// dp
// 0 0 0 0 0 0 0 0 
// 0 0 15 15 15 15 15 15 
// 0 0 15 15 15 15 15 29 
// 0 10 15 25 25 25 25 29 
// 0 10 15 45 55 60 70 70 
// 0 10 15 45 55 60 70 75


// fractional knapsack
// 0-1 Knapsack
// Unbounded Knapsack



