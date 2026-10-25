#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){   // Euclidian Algorithm
    if((a%b)==0) return b;
    return gcd(b,a%b);
}


int main()
{
    cout<<gcd(60,36)<<endl;
    cout<<"GCD = "<<__gcd(60,36)<<endl;
    cout<<"LCM = "<<(60 * 36)/(__gcd(60,36))<<endl;

    return 0;
}


//        GCD
//   eg. gcd of 36 & 60 
//        ____ 
//     36_| 60
//        - 36
//        ------______
//          24 _| 36   
//              - 24
//             --------_____
//                12  _| 24
//                     - 24
//                    --------
//                       00
//   
//   Therefore GCD = 12.





