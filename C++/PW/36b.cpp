#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];

int frog(int arr[],int i){
    if(dp[i] != -1) return dp[i];
    if(i == 0) return dp[i] = 0;
    if(i == 1) return dp[i] = frog(arr,i-1)+abs(arr[i]-arr[i-1]);

    return dp[i] = min((frog(arr,i-1)+abs(arr[i]-arr[i-1])) , (frog(arr,i-2)+abs(arr[i]-arr[i-2])));
}

int main() {
    
    int arr[] = {10,30,40,60,50,20};
    memset(dp,-1,sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<frog(arr,n-1);


    return 0;
}
