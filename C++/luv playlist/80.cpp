#include<bits/stdc++.h>
using namespace std;

// some error is there

bool isVowel(char ch){
    return ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'||ch == 'u'; 
}

vector<string> subsets(string s){
    int sz = (1<<s.size());
    vector<string> ans;
    for(int mask = 0;mask < sz;mask++){
        string subset;
        for(int bit = 0;bit<s.size();bit++){
            if(mask & (1<<bit)) subset.push_back(s[bit]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    unordered_map<string,int> hsh;
    for(int i=0;i<n;i++){
        set<char> distinct_vw;
        for(char ch:str[i]){
            if(isVowel(str[i])){
                distinct_vw.insert(ch);
            }
        }
        string vowel_str;
        for(char ch:distinct_vw)
            vowel_str.push_back(ch);
        vector<string> all_subsets = subsets(vowel_str);
        for(string vowel_subset : all_subsets){
            hsh[vowel_subset]++;
        }
    }
    long long ans = 0;
    for(auto &pr : hsh){
        if(pr.second < 3) continue;
        long long ct = pr.second;
        long long ways = ct * (ct-1) * (ct-2)/6;
        if(pr.first.size()%2 == 0) ans-=ways;
        else ans+=ways;
    }






    return 0;
}


