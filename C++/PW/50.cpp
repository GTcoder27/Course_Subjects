#include <bits/stdc++.h>
using namespace std;

int binarySearchFirst(vector<int> &v,int l,int r,int tofind){
    if(l>r) return-1;
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
    return binarySearchFirst(v,l,r,tofind);
}
int binarySearchLast(vector<int> &v,int l,int r,int tofind){
    if(l>r) return-1;
    int mid = (l+r)/2;
    if(v[mid] == tofind){
        if(v[mid+1] == tofind){
            l = mid+1;
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
    return binarySearchLast(v,l,r,tofind);
}



int main() {
    
    vector<int> v = {1,3,3,3,3,3,3,11};
    int tofind = 3;
    vector<int> ans;
    ans.push_back(binarySearchFirst(v,0,v.size()-1,tofind));
    ans.push_back(binarySearchLast(v,0,v.size()-1,tofind));
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}
