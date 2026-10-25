#include <bits/stdc++.h>
using namespace std;
// Bucket sort




void bucketSort(float arr[],int size){

    // step 1] 
    vector<vector<float>> bucket(size, vector<float> ());

    //step 2] inserting elements into bucket
    for(int i=0;i<size;i++){
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
    }

    // step 3] sorting individual buckets 
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // step 4] combining elements from bucket
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++] = bucket[i][j];
        }
    }
    

}


int main() {

    float arr[] = {0.10,0.28,0.24,0.6,0.34,0.18,0.38,0.44};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
