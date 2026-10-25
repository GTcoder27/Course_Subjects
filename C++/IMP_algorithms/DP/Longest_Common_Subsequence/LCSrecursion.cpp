#include<bits/stdc++.h>
using namespace std;
// Longest Common Subsequence using recursion


int dp[1005][1005];
    
int lcs(int i,int j,string &s1,string &s2){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    // remove 1 char from s1 and s2
    if(s1[i] == s2[j]){
        ans = lcs(i-1,j-1,s1,s2)+1;
    }
    else{
        // remove ith char from s1  or  remove jth char from s2 
        ans = max(lcs(i,j-1,s1,s2),lcs(i-1,j,s1,s2));
    }

    return dp[i][j] = ans;
}




int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n1 = s1.size();
    int n2 = s2.size();

    memset(dp,-1,sizeof(dp));

    cout<<lcs(n1-1,n2-1,s1,s2);

    return 0;
}


// input 
// abcde
// ace

// output
// 3
