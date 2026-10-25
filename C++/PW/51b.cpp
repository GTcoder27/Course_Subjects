#include <bits/stdc++.h>
using namespace std;
// finding element from 2d array using Binary search


bool binarySearch(vector<vector<int>> arr,int target){
    int n = arr.size();
    int m = arr[0].size();
    int lo = 0,hi = n*m -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        int x = mid/m;
        int y = mid%m;
        if(arr[x][y] == target){
            return true;
        }
        else if(arr[x][y] < target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int> > arr = {{1,3,5,7},
                    {10,11,16,20},
                    {23,30,34,50}};
    
    cout<<binarySearch(arr,16);

    return 0;
}
