#include <bits/stdc++.h>
using namespace std;
// Insertion Sort = O(n^2)


int main() {
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int current = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > current){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
   
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
// 5
// 11 8 15 9 4