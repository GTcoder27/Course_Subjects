#include <bits/stdc++.h>
using namespace std;
// finding minimum from sorted rotated array


int mini(vector<int> &v){

    if(v.size() == 1) return v[0];
    int l = 0 , r = v.size()-1;
    if(v[l] < v[r]) return l;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(v[mid] > v[mid+1]) return mid+1;
        if(v[mid] < v[mid-1]) return mid;
        if(v[mid] > v[l]){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}



int main() {
    
    vector<int> v = {9,2,5,7,8};
    cout<<mini(v);


    return 0;
}
