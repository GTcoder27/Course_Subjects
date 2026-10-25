#include <bits/stdc++.h>
using namespace std;



int main(){

    map<int,string> map1 = {{454,"giri"},{123,"jkscdb"},{634,"jkdsc"}};
    map<int,string,greater<int>> map2 ;
    map2.insert(make_pair(235,"dvsjkb"));
    map2.insert(make_pair(634,"jkdsc"));
    map2.insert(make_pair(134,"jkfdsc"));

    for(auto i:map1){
        cout<<i.first<<" "<<i.second<<endl;;
    }
    for(auto i:map2){
        cout<<i.first<<" "<<i.second<<endl;;
    }
    cout<<endl;
    
    map1.erase(map1.begin());
    map1.erase(123);
    map2.erase(++map2.begin(),map2.end()); // end operator done not get delete

    for(auto i:map1){
        cout<<i.first<<" "<<i.second<<endl;;
    }
    for(auto i:map2){
        cout<<i.first<<" "<<i.second<<endl;;
    }

    cout<<map2.max_size()<<endl;
    cout<<map2.size()<<endl;










    
    return 0;
}
