// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string str;
//     cin>>str;
//     stack<int> s;
//     for(int i=0;i<str.size();i++)
//     {
//         if(str[i]=='{' || str[i]=='[' || str[i]=='('){
//             s.push(str[i]);
//         }
//         else{
//             if(str[i]=='}'&&s.top()=='{'){
//                 s.pop();
//             }
//             else if(str[i]==')'&&s.top()=='('){
//                 s.pop();
//             }
//             else if(str[i]==']'&&s.top()=='['){
//                 s.pop();
//             }
//             else{
//                 cout<<"NO";
//             }
//         }
//     }
//     if(s.empty()){
//         cout<<"YES";
//     }
//     return 0;
// }


//////OR//////




#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> symbols = {{'{',-1},{'[',-2},{'(',-3},{'}',1},{']',2},{')',3}};
string isBalanced(string &s)
{
    stack<char> st;
    for(auto i:s)
    {
        if(symbols[i]<0){
            st.push(i);
        }
        else {
            if(st.empty()) return "NO";
            char top = st.top();
            st.pop();
            if( (symbols[top]+symbols[i])!=0 ){
                return "NO";
            }
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}



int main()
{
    string s;
    cin>> s;
    cout<<isBalanced(s);
    return 0;
}