#include <bits/stdc++.h>
using namespace std;
// Selection Sort = O(n^2)


int main() {
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++){
        int min_i = i;
        for(int j=i;j<n;j++){
            if(v[min_i] > v[j]){
                min_i = j;
            } 
        }
        swap(v[min_i],v[i]);

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