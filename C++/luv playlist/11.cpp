#include<bits/stdc++.h>
using namespace std;
void inc(int &a,int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

main()
{
    int a = 20,b = 30;
    cout<<a<<" "<<b<<endl;
    inc(a,b);
    cout<<a<<" "<<b<<endl;

    
}