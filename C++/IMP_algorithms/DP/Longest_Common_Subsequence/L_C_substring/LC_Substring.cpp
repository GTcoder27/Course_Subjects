#include<bits/stdc++.h>
using namespace std;
// Longest Common Substring using tabulation

int lcs(int n1,int n2,string s1,string s2,vector<vector<int>> &dp){
    
    for(int i = 0; i < n1+1;i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < n2+1;i++){
        dp[0][i] = 0;
    }
    int ans = 0;

    for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return ans;

}



int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    cout<<lcs(n1,n2,s1,s2,dp);

    return 0;
}



// input 
// abcdgh
// acdghr

// output
// 4
