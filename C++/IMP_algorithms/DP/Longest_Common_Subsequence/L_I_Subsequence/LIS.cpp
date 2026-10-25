#include<bits/stdc++.h>
using namespace std;
// Longest increasing subsequence 

int LIS(int n1,int n2,vector<int> &arr1,vector<int> &arr2,vector<vector<int>> &dp){
    
    for(int i = 0; i < n1+1;i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < n2+1;i++){
        dp[0][i] = 0;
    }


    for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}



int main(){
    int n1 ;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }

    // we are using set because we need strictly increasing
    set<int> s(arr1.begin(),arr1.end());
    vector<int> arr2(s.begin(),s.end());
    int n2 = arr2.size(); 

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    
    cout<<LIS(n1,n2,arr1,arr2,dp)<<endl;
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}



// input 
// 6
// 50 3 10 7 40 80

// output
// 4
