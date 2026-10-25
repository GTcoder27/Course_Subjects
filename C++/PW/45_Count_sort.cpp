#include <bits/stdc++.h>
using namespace std;
// Count sort


void countSort(vector<int> &v){

    int n = v.size();

    // finding max element 
    int max_e = INT_MIN;
    for(int i=0;i<n;i++){
        max_e = max(max_e,v[i]);
    }

    // create the frequency array
    vector<int> freq(max_e+1,0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }

    // calculate the cumulative frequency array
    for(int i=1;i<=max_e;i++){
        freq[i] += freq[i-1];
    }

    // calculate the sorted array
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]] = v[i];
    }

    // copy the ans array to origional array
    for(int i=0;i<n;i++){
        v[i] = ans[i];
    }


}


int main() {

    vector<int> v = {10,28,24,6,34,18,38,44};
    countSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}
