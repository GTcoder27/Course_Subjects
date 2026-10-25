#include<bits/stdc++.h>
using namespace std;

// Modular Multiplicative inverse question 

const int M = 1e9+7;

int binexp(int a, int b,int m ){
    int result = 1;
    while(b>0){
        if(b&1){
            result = (result*1LL*a) % m;
        }
        a = (a*1LL*a) % m;
        b >>= 1; 
    }
    return result;
}

const int N = 1e5+10;
int fact[N];

//Alphabate --> K symbols, N size Password
// KCN --> N! * KCN 
// a , b , c --> 3*2*1 --> n! 


 

int main()
{
    int t;
    cin>>t;
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*1LL*i) % M;
    }
    while(t--){
        int n,k;
        cin>>n>>k;
        int ans = fact[n];
        ans = (ans * 1LL * fact[k]) % M;
        int den = (fact[k-n] * 1LL * fact[n]) % M;
        ans = (ans * 1LL * binexp(den,M-2,M)) % M;
        cout<<ans<<endl;
    }

    






    return 0;
}
