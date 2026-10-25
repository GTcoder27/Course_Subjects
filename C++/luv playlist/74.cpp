#include<bits/stdc++.h>
using namespace std;

// Modular Multiplicative inverse 

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

// There are N children and K toffees. K < N
// Count the number of ways to distribute toffee
// among N students such that each students get 
// 1 toffee only --> nCK % M , M = 10^9+7
// N < 10^6, K < N < 10^6
// n ! / ((n-r)! * r!)

const int N = 1e6+10;
int fact[N];

int main()
{
    fact[0] = 1;
    for(int i=0;i<N;i++){
        fact[i] = (fact[i-1] * 1LL * i) % M; 
    }
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        int ans = fact[n];
        int den = (fact[n-k]*1LL*fact[k]) % M ; 
        ans = ans*binexp(den,M-2,M);
        cout<<ans<<endl;
    }
    






    return 0;
}
