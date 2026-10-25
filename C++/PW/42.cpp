#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0;j<n-i-1;j++){
            if(v[j] == 0 && v[j+1] != 0){
                swap(v[j],v[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
        for(int k=0;k<n;k++){
            cout<<v[k]<<" ";
        } 
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

// input
// 6
// 0 5 0 3 4 2