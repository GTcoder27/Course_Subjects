#include <bits/stdc++.h>
using namespace std;

// find max from subarray

int makeST(vector<int> &arr,int left,int right,vector<int> &st,int index){

    if( left == right ) {
        st[index] = arr[left];
        return st[index];
    }
    int mid = (left+right)/2;
    int left_subtree = makeST(arr,left,mid, st ,2*index+1);
    int right_subtree = makeST(arr,mid+1,right, st ,2*index+2); 

    st[index] = max(left_subtree, right_subtree);
    return st[index];
}



int getMaxUtil(vector<int> &st,int i, int si, int sj, int qi, int qj){
    if(qj < si || qi > sj) { //non overlapping
        return INT_MIN;
    }
    else if(si >= qi && sj <= qj) { //complete overlap
        return st[i];
    }
    else { //partial overlap
        int mid = (si + sj) / 2;
        int left = getMaxUtil(st,2*i+1, si, mid, qi, qj);
        int right = getMaxUtil(st,2*i+2, mid+1, sj, qi, qj);
        return max(left , right);
    }

}



void updateUtil(vector<int> &st,int i, int si, int sj, int idx, int newvalue) {
    if(idx > sj || idx < si) {
        return;
    }
    
    st[i] = max(newvalue,st[i]);

    if(si != sj) { //non-leaf
        int mid = (si + sj)/2;
        updateUtil(st,2*i+1, si, mid, idx, newvalue); //left
        updateUtil(st,2*i+2, mid+1, sj, idx, newvalue); //right
    }
}
    




int main(){

    int n;
    cin >> n;
    int qi,qj;
    cin>>qi>>qj;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> st(4*arr.size()+1);

    cout<<makeST(arr,0,n-1,st,0)<<endl;

    for(int i=0;i<st.size();i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;

    cout<<getMaxUtil(st,0,0,n-1,qi,qj)<<endl;
    
    int newvalue = 10;
    int diff = newvalue - arr[2];
    arr[2] = newvalue;
    updateUtil(st,0,0,n-1,2,newvalue);
    
    cout<<getMaxUtil(st,0,0,n-1,qi,qj)<<endl;


    return 0;
}




// input 
// 9
// 1 3
// 6 8 -1 2 17 1 3 2 4



