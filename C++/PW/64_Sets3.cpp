#include <bits/stdc++.h>
using namespace std;
// Sets


bool checkAll(string s){
    if(s.length()<26){
        return false;
    }
    transform(s.begin(),s.end(),s.begin(),::tolower);
    set<char> set1;
    for(char i:s){
        set1.insert(i);
    }
    return (set1.size() == 26);
}

int main(){

    string s;
    cin>>s;
    cout<<checkAll(s);

    return 0;
}
