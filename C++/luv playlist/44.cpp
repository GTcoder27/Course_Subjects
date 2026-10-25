#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int min = *min_element(v.begin()+3,v.end());
    cout<<"min = "<<min<<endl;
    int max = *max_element(v.begin(),v.end());
    cout<<"max = "<<max<<endl;
    int sum = accumulate(v.begin()+1,v.end(),0);
    cout<<"sum = "<<sum<<endl;
    int ct = count(v.begin(),v.end(),2);
    cout<<"count = "<<ct<<endl;
    auto it = find(v.begin(),v.end(),2);
    if(it != v.end()){
        cout<<"we got it = "<<*it<<endl;
    }
    else {
        cout<<"Element Not Found"<<endl;
    }
    reverse(v.begin(),v.end());
    for(auto &i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    string a = "girish vijay nandanwar";
    reverse(a.begin(),a.end());
    for(auto &i:a){
        cout<<i<<" ";
    }



    
    return 0;
}