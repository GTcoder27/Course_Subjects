#include <bits/stdc++.h>
using namespace std;
// Decode string 
// not done try ones again

int main() {
    
    string s = "2[abc]3[cd]ef";
    // string s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    string ans;
    string result;
    // string temp_str; 
    for(int i=0;i<s.size();i++){
        if(s[i] == ']'){
            string temp;
            while(result[result.size()-1] != '['){
                temp += result[result.size()-1];
                result.pop_back();
            }
            reverse(temp.begin(),temp.end());
            result.pop_back();
            int count = result[result.size()-1] - '0';
            result.pop_back();
            temp = temp + ans;
            // cout<<temp<<endl;
            ans.clear();
            while(count--){
                ans += temp;
            }
        }
        else{
            result += s[i];
        }
        // cout<<result<<endl;
    }
    cout<<ans;
    



    return 0;
}
