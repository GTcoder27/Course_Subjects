#include <bits/stdc++.h>
using namespace std;
// Binary Search (Recursive approach)


int binarySearch(vector<int> &v,int l,int r,int tofind){
    if(l == r) return -1;
    int mid = (l+r)/2;
    if(v[mid] == tofind) return mid;
    else if(v[mid] > tofind){
        r = mid-1;
    }
    else if(v[mid] < tofind){
        l = mid+1;
    }
    return binarySearch(v,l,r,tofind);
}



int main() {
    
    vector<int> v = {23, 25, 38, 43, 45};

    cout<<binarySearch(v,0,v.size()-1,25);


    return 0;
}
