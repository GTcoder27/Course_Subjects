#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

// don't use power function (eg. pow(2,3) ) in competitive programming contests
// because it returns value in double which is not fixed value

int binExpRecur(int a, int b){
    if(b==0) return 1;
    int res = binExpRecur(a,b/2);
    if(b&1){  // b&1 is same as b%2!=0 , but b&1 is fast.
        return (a*(res*1LL*res)%M)%M;
    }
    else{
        return (res*1LL*res)%M;
    }
}

int binExpIter(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){  
            ans = (ans * 1LL *a)%M;
        }
        a = (a * 1LL * a)%M;
        b = b>>1;
    }
    return ans;
}


int main()
{
    int a = 678,b = 3;
    cout<<binExpRecur(a,b)<<endl;
    cout<<binExpIter(a,b);


    return 0;
}
