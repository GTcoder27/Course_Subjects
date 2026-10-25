#include <bits/stdc++.h>
using namespace std;



int binarySearch(vector<int> &v,int l,int r,int tofind){
    if(l==r) return-1;
    int mid = (l+r)/2;
    if(v[mid] == tofind){
        if(v[mid-1] == v[mid]){
            r = mid-1;
        }
        else{
            return mid;
        }
    }
    else if(v[mid] > tofind){
        r = mid-1;
    }
    else if(v[mid] < tofind){
        l = mid+1;
    }
    return binarySearch(v,l,r,tofind);
}



int main() {
    
    vector<int> v = {1,3,3,3,3,5,11};
    int tofind = 3;
    cout<<binarySearch(v,0,v.size()-1,tofind);


    return 0;
}
