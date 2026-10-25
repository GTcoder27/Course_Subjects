#include<bits/stdc++.h>
using namespace std;
//  

int main()
{
    int a = 10;
    int &d = a;
    int *b = &a;
    b++;
    int **c = &b;

    cout << &a << endl;
    cout << b << endl;
    cout << &b << endl;
    cout << c << endl;
    cout << **c << endl;
    a = 23;
    d++;
    cout << **c << endl;
    cout << &d << endl;

    

    return 0;
}
