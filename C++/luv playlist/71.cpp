#include<bits/stdc++.h>
using namespace std;


int main()
{
    // int n;
    // cin>>n;
    // if(n==1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    // bool is_prime = true;
    // for(int i=2;i*i<=n;i++){  
    //     if(n%i == 0){
    //         is_prime = false;
    //         break;
    //     }
    // }
    // cout<<is_prime<<endl;



    // int n;
    // cin>>n;
    // vector<int> prime_factors;
    // for(int i=2;i<=n;i++){
    //     while(n%i == 0){
    //         prime_factors.push_back(i);
    //         n = n/i;
    //     }
    // }
    // for(auto i:prime_factors){
    //     cout<<i<<" ";
    // }
    
    
    
    int n;
    cin>>n;
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            prime_factors.push_back(i);
            n = n/i;
        }
    }
    if(n>1){
        prime_factors.push_back(n);
    }
    for(auto i:prime_factors){
        cout<<i<<" ";
    }





    return 0;
}
