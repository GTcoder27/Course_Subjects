#include <bits/stdc++.h>
using namespace std;
// Bubble Sort optimised


int main() {
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int j=0;j<n-1;j++){
        bool flag = false;
        for(int i=0;i<n-j-1;i++){
            if(v[i] > v[i+1]){
                flag = true;
                swap(v[i],v[i+1]); 
            }
        }
        if(!flag) break;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

// input
// 5
// 20 50 40 10 30