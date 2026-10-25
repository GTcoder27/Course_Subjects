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

    // multiply / divide by 2
    int n = 5;
    cout<<(n>>1)<<endl;  // n/2
    cout<<(n<<1)<<endl;  // n*2

    return 0;
}