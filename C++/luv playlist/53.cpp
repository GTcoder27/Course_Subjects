#include<bits/stdc++.h>
using namespace std;
// Predicate Function = which returns only true/false.  
// ex : T T T T T F F F F F F F F ...
//      F F F F T T T T T T T T T ... 
const int N = 1e6+10; 
int n;  // number of trees 
long long m;  // amount of wood needed
long long trees[N];  

bool isWoodSufficient(int h){
    long long wood;
    for(int i=0;i<n;i++){
        if(trees[i] >= h){
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>trees[i];
    }
    long long lo = 0,hi = 1e9,mid;
    // T T T T F F F F F
    while(hi-lo > 1){
        mid = (hi-lo)/2;
        if(isWoodSufficient(mid)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    if(isWoodSufficient(hi)){
        cout<<hi<<endl;
    }
    else{
        cout<<lo<<endl;
    }


    return 0;
}