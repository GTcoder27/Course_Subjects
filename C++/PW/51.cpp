#include <bits/stdc++.h>
using namespace std;
// finding largest element from mountain array using Binary search


int large(vector<int> &v){
    int l = 0;
    int r = v.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(v[mid] > v[mid+1] && v[mid] > v[mid-1]) return mid;
        else if(v[mid] > v[mid-1]){
            l = mid+1;
        }
        else if(v[mid] > v[mid+1]){
            r = mid-1;
        }
    }
    return -1;
}



int main() {
    
    vector<int> v = {0,2,3,4,1,0};
    cout<<large(v);


    return 0;
}
