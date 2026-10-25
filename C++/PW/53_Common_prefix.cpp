#include <bits/stdc++.h>
using namespace std;
// longest common prefix

int main() {
    
    vector<string> strs = {"flower","flow","flight"};
    sort(strs.begin(),strs.end());
    string prefix;
    for(int i=0;i<strs[0].size();i++){
        if(strs[0][i]==strs[strs.size()-1][i]) prefix += strs[0][i];
        else break;
    }
    cout<<prefix;
    



    return 0;
}
