#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Ganpati Bappa Morya"<<endl;
    // int n ;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // sort(a,a+n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // int *ptr = lower_bound(a,a+n,5);
    // if(ptr == (a+n)){
    //     cout<<"Not Found";
    //     return 0;
    // }
    // cout<<(*ptr)<<endl;

    // // int *ptr = upper_bound(a,a+n,3);
    // // if(ptr == (a+n)){
    // //     cout<<"Not Found";
    // //     return 0;
    // // }
    // // cout<<(*ptr)<<endl;




    // int n ;
    // cin>>n;
    // vector<int> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // sort(v.begin(),v.end());
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // auto it = lower_bound(v.begin(),v.end(),5);
    // if(it == v.end()){
    //     cout<<"Not Found";
    //     return 0;
    // }
    // cout<<(*it)<<endl;

    

    // For Sets & Maps

    set<int> s;
    map<int,int> m;
    for(int i=0;i<(int)(1e6);i++){
        s.insert(rand());
    } 
    for(int i=0;i<(int)(1e5);i++){
        auto it = s.lower_bound(rand());
    } 
    cout<<"executed ";


    return 0;
}