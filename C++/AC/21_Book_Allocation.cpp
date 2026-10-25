// Book Allocation Problem

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxAllowedPages){
    int students = 1,pages = 0;

    for(int i=0;i<n;i++){
        if(arr[i] > maxAllowedPages) return false;
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        } else{
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}


int allocateBooks(vector<int> &arr,int n,int m){  //O(N log N)
    if(m > n) return -1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int ans = -1;
    int st = 0,end = sum;
    while(st <= end){
        int mid = (st + end) / 2;
        cout<<mid<<" ";
        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}


int main() {
    vector<int> arr = {2,1,3,4};
    int n = 4,m = 1;
    cout<<allocateBooks(arr,n,m)<<endl;
    return 0;
}