#include <bits/stdc++.h>
using namespace std;
// Bubble Sort


int main() {
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n-j-1;i++){
            if(v[i] > v[i+1]){
                swap(v[i],v[i+1]); 
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

// input
// 5
// 20 50 40 10 30