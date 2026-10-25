#include <bits/stdc++.h>
using namespace std;
// Radix sort


void countSort(vector<int>& v,int pos){

    int n = v.size();
    // create frequency array
    vector<int> freq(10,0);
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }

    // calculate cumulative frequency
    for(int i=1;i<10;i++){
        freq[i] += freq[i-1];
    }

    // calculate the sorted array
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]] = v[i];
    }

    // copy the ans array to origional array
    for(int i=0;i<n;i++){
        v[i] = ans[i];
    }
}

void radixSort(vector<int> &v){

    int max_e = INT_MIN;
    for(int i:v){
        max_e = max(max_e,i);
    }

    for(int pos = 1;max_e/pos > 0;pos *= 10){
        countSort(v,pos);
    }
    

}


int main() {

    vector<int> v = {10,28,24,6,34,18,38,44};
    radixSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}
