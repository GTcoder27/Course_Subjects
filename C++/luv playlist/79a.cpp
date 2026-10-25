#include<bits/stdc++.h>
using namespace std;

// __builtin_popcountll(x) is a inbuilt function 
// It is used to find out set bits of any number.

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        cout<<__builtin_popcountll(x)<<endl;
    }

    return 0;
}


