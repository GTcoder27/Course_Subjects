#include<bits/stdc++.h>
using namespace std;
// XOR : 1 ^ 0 -> 1
//       0 ^ 1 -> 1
//       0 ^ 0 -> 0
//       1 ^ 1 -> 0


void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}


int main()
{
    int a = 4,b = 6;
    printBinary(a);
    printBinary(b);

    // swappping of two numbers
    a = a ^ b;
    printBinary(a);
    b = a ^ b;
    printBinary(b);
    a = a ^ b;
    printBinary(a);
    cout<<a<<" "<<b<<endl;
    

    int n;
    cin>>n;
    int x;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>x;
        ans ^= x;
    }
    cout<<ans<<endl;
    return 0;
}
