#include <bits/stdc++.h>
using namespace std;
// Sets


int main(){

    set<int> set1;

    set1.insert(30);
    set1.insert(10);
    set1.insert(20);
    set1.insert(40);
    set1.insert(60);
    set1.insert(70);
    set1.insert(50);

    cout<<set1.size()<<endl;
    set1.insert(10);
    cout<<set1.size()<<endl;

    for(auto it=set1.begin();it!=set1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it:set1){
        cout<<it<<" ";
    }
    cout<<endl;
    
    set1.erase(30);
    set1.erase(set1.begin());
    set1.erase(++(set1.begin()),--(set1.end()));

    for(auto it:set1){
        cout<<it<<" ";
    }
    cout<<endl;
    set1.insert(30);
    set1.insert(10);
    set1.insert(20);
    set1.insert(40);
    set1.insert(60);
    set1.insert(70);
    set1.insert(50);

    if(set1.find(30)!=set1.end()){
        cout<<"present \n";
    }else{
        cout<<"not present \n";
    }
    for(auto it:set1){
        cout<<it<<" ";
    }
    cout<<endl;
    
    cout<<*(set1.lower_bound(11))<<endl;
    cout<<*(set1.upper_bound(20))<<endl;






    return 0;
}
