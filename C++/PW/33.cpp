#include<bits/stdc++.h>
using namespace std;





int main()
{
    string str = "abcax";
    char ch = 'a';
    // str.erase(remove(str.begin(),str.end(),ch),str.end());
    str.erase(str.begin()+1);

    cout<<str;

    

    return 0;
}
