#include <bits/stdc++.h>
using namespace std;
// unordered map
// multimap
// unordered multimap



int main(){

    multimap<int,string> map2 ;
    map2.insert(make_pair(235,"h"));
    map2.insert(make_pair(235,"h"));
    map2.insert(make_pair(134,"jkfdsc"));
    // map2[34] = "sdchb"; it is not allowed  

    for(auto i:map2){
        cout<<i.first<<" "<<i.second<<endl;;
    }
    








    
    return 0;
}
