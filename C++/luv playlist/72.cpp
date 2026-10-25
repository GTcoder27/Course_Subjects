#include<bits/stdc++.h>
using namespace std;

// sieve algorithm 

const int N = 1e7+10;
vector<bool> isPrime(N,1);


int main()
{
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<N;i++){
        if(isPrime[i] == true){
            for(int j=i*2;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    
    for(int i=0;i<20;i++){
        cout<<i<<" = "<<isPrime[i]<<endl;
    }





    return 0;
}
