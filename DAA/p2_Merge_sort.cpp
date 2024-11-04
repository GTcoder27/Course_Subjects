#include <bits/stdc++.h>
using namespace std;
// merge Sort = O(n log(n))

void merge(int arr[],int l,int mid,int r){

    int a_size = mid - l + 1;
    int b_size = r - mid;
    // create 2 temp arrays
    int a[a_size],b[b_size];

    for(int i=0;i<an;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<an;i++){
        b[i] = arr[mid+1+i];
    }
    int i=0; //initial index of first subarray , a
    int j=0; //initial index of second subarray , b
    int k=l; //initial index of merged subarray
    while(i<an && j<bn){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<an){
        arr[k++] = a[i++];
    }    
    while(j<bn){
        arr[k++] = b[j++];
    }    
}

void merge_sort(int arr[],int l,int r){
    if(l >= r){
        return;
    }
    int mid = (l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main() {
    int arr[] = {10,28,24,6,34,18,38,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

