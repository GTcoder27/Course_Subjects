#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binExp(long long a, long long b){
    int ans = 1;
    while(b>0){
        if(b&1){  
            ans = binMultiply(ans,a);
        }
        a = binMultiply(a,a);
        b = b>>1;
    }
    return ans;
}
int binMultiply(long long a, long long b){
    int ans = 0;
    while(b>0){
        if(b&1){  
            ans = (ans+a)%M;
        }
        a = (a+a)%M;
        b = b>>1;
    }
    return ans;
}




int main()
{
    // int a = 678,b = 3;
    cout<<binExp(2,10);


    return 0;
}
