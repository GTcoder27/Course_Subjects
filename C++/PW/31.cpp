#include<bits/stdc++.h>
using namespace std;
//  fibonachi series by dp

const int N = 1e5; 
int dp[100];

int fibo(int n){
    if(dp[n] != -1) return dp[n];
    if(n==0){
        return dp[n] = n;
    }
    if(n==1){
        return dp[n] = n;
    }
    return dp[n] = fibo(n-1)+fibo(n-2);
}

// 0 1 1 2 3 5 8 13

int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<fibo(4);

    

    return 0;
}
