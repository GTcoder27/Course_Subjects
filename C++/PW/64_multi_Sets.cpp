#include <bits/stdc++.h>
using namespace std;
// Multi Sets



int main(){

    multiset<int ,greater<int>> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);
    for(auto value:ms){
        cout<<value<<" ";
    }cout<<endl;
    cout<<ms.count(3);

    return 0;
}
