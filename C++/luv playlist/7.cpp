#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{   
    // string s;
    // cin>>s;
    // string rev_s;
    // for(int i=s.size()-1;i>=0;i--)
    // {
    //     // rev_s = rev_s + s[i];
    //     rev_s.push_back(s[i]);
    // }
    // cout<<rev_s<<endl;
    // if(rev_s == s)
    // {
    //     cout<<"It is palindrome ";
    // }
    // else{
    //     cout<<"no";
    // }

    // string s;
    // cin>>s;
    // int last = s.size();
    // int pall = 1;
    // for(int i=0;i<(last/2);i++)
    // {
    //     if(s[i] != s[--last])
    //     {
    //         pall = 0;
    //         break;
    //     }
    // }
    // if(pall == 0)
    // {
    //     cout<<"NO";
    // }
    // else
    // {
    //     cout<<"YES";
    // }

    string str;
    cin>>str ;
    for(int i=0;i<str.size()/2;i++)
    {
        if(str[i] != str[str.size()-i-1])
        {
            cout<<"It is not pallindrome";
            break;
        }
    }










    return 0;
}