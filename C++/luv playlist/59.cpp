#include<bits/stdc++.h>
using namespace std;
//     set bit -> 1
// not set bit -> 0
// ~ (tilda operator) (say inversion) = it invert the binary i.e 1's complement of binary
// toggle = convert 1 to 0 & convert 0 to 1;
// & -> and
// | -> or
// ^ -> Xor


void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main()
{
    cout<<(~5)<<endl;
    printBinary(~5);
    int a = 9;
    int i = 3;
    if((a & (1<<i)) != 0){
        cout<<"set bit \n";
    }
    else{
        cout<<"not set bit \n";
    }

    // bit set 
    printBinary(a | (1<<1));
    // bit unset
    printBinary(a & (~(1<<3)));

    // toggle
    printBinary(a ^ (1<<2));
    printBinary(a ^ (1<<3));
    
    int ct = 0;
    for(int i=31;i>=0;i--){
        if((a&(1<<i)) != 0){
            ct++;
        }
    }
    cout<<ct<<endl;

    cout<<__builtin_popcount(a)<<endl; // used to find out number of set bits 
    cout<<__builtin_popcount(a)<<endl; // this is valid for integers only



    return 0;
}