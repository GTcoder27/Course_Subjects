#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int n){
    if(n/10 == 0) return n%10;
    return (n%10) + sum_of_digits(n/10);
}



int main()
{
    cout<<sum_of_digits(45513);

    

    return 0;
}
