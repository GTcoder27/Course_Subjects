#include<bits/stdc++.h>
using namespace std;


int dp[N];
// Top down approch

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    // memoise karna 

    return dp[n] = fib(n-1) + fib(n-2);
}




int main()
{
    memset(dp,-1,sizeof(dp));  // memset function will fill the dp array by -1.
                               // we can also use for loop for this 
    int n;
    cin>>n;
    cout<<fib(n);

    // Bottom up approch
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }


}


// input
