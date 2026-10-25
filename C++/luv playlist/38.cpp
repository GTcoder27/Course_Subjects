#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(9);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    queue<string> q;
    q.push("nda");
    q.push("hsc");
    q.push("ssc");
    q.push("neet");
    q.push("jee");
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}