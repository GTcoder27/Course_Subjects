#include<bits/stdc++.h>
using namespace std;

// to find divisors



int main()
{
    int n;
    cin>>n;
    int ct = 0;
    int sum = 0;
    for(int i=1;i*i<=n;i++){  // & for(int i=1;i<=sqrt(n);i++)  both are same
        if(n%i == 0){
            cout<<i<<" "<<n/i<<endl;
            ct+=1;
            sum+=1;
            if(n/i != i){
                sum += n/i;
                ct+=1;
            }
        }
    }
    cout<<ct<<" "<<sum<<endl;


    return 0;
}
