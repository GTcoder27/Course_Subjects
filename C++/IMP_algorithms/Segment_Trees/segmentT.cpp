#include <bits/stdc++.h>
using namespace std;

int makeST(vector<int> &arr,int left,int right,vector<int> &st,int index){

    if( left == right ) {
        st[index] = arr[left];
        return st[index];
    }
    int mid = (left+right)/2;
    int left_subtree = makeST(arr,left,mid, st ,2*index+1);
    int right_subtree = makeST(arr,mid+1,right, st ,2*index+2); 

    st[index] = left_subtree + right_subtree;
    return st[index];
}




int main(){

    int n;
    cin >> n;

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


    return 0;
}




// input 
// 8
// 1 2 3 4 5 6 7 8


