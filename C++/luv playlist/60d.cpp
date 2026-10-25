#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main()
{
    // clear LSB's

    int a = 59;
    printBinary(a);
    int i = 4;
    int b = (a & ~((1<<i+1)-1));
    printBinary(b);

    // clear MSB's

    int x = 59;
    printBinary(x);
    int j = 3;
    int y = (x & ((1<<j+1)-1));
    printBinary(y);




    return 0;
}
