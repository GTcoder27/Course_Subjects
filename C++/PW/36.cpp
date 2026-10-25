#include<bits/stdc++.h>
using namespace std;

int find_gcd(int a,int b){
    if(a<=1 || b<=1) return 1;
    if(a%b == 0) return b;
    if(b%a == 0) return a;
    if(a>b){
        return find_gcd(a-b,b);
    }
    else{
        return find_gcd(a,b-a);
    }
}



int main()
{
    cout<<find_gcd(12,20);
    // cout<<__gcd(54,72);

    

    return 0;
}
