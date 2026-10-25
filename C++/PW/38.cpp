#include <bits/stdc++.h>
using namespace std;
// posible string from nokia 2310

vector<string> subsets;
map<char,string> button;



    void generate(string s,int i,string subset){

        if(i == s.size()){
            subsets.push_back(subset);
            return;
        }
        char num = s[i];
        for(int j=0;j<button[num].size();j++){
            subset.push_back(button[num][j]);
            generate(s,i+1,subset);
            subset.pop_back();
        }
    }


int main() {
    
    button['2'] = "abc";
    button['3'] = "def";
    button['4'] = "ghi";
    button['5'] = "jkl";
    button['6'] = "mno";
    button['7'] = "pqrs";
    button['8'] = "tuv";
    button['9'] = "wxyz";
    string input;
    cin>>input;
    string subset;
    generate(input,0,subset);

    for(string i:subsets){
        cout<<i<<" ";
    }

    return 0;
}

