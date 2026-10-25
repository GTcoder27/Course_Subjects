// Painters Partition Problem

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxAllowedTime){
    int painters = 1,time = 0;

    for(int i=0;i<n;i++){
        if(arr[i] > maxAllowedTime) return false;
        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        } else{
            painters++;
            time = arr[i];
        }
    }
    return painters <= m;
}


int minTimeToPaint(vector<int> &arr,int n,int m){  //O(N log N)

    int sum = 0,maxVal = INT_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxVal = max(maxVal,arr[i]);
    }
    int ans = -1, st = maxVal,end = sum;
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
    vector<int> arr = {40,30,10,20};
    int n = 4,m = 2;
    cout<<minTimeToPaint(arr,n,m)<<endl;
    return 0;
}