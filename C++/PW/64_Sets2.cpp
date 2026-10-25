#include <bits/stdc++.h>
using namespace std;
// Sets


int main(){

    int n;
    cin>>n;
    set<string> set1;
    while(n--){
        string s;
        cin>>s;
        set1.insert(s);
    }
    for(auto i:set1){
        cout<<i<<" ";
    }
    cout<<endl;






    return 0;
}
