#include<bits/stdc++.h>
using namespace std;


const int N = 1e5; 
int dp[100][100];

int power_f(int a,int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(b==0) return dp[a][b] = 1;
    if(b==1) return dp[a][b] = a;
    if(b%2 == 0){
        return dp[a][b] = power_f(a,b/2) * power_f(a,b/2);
    }
    else{
        return dp[a][b] = power_f(a,b/2) * power_f(a,(b/2)+1);
    }
}



int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<power_f(2,6);

    

    return 0;
}
