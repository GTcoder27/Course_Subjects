#include<bits/stdc++.h>
// #include<iostream>
using namespace std;


int main()
{
    int a[]={4,6,2,8,9};
    int temp = 2; 
    for(int k=1;k<=5;k++){

        for(int j=k;j<k+temp;j++){
            cout<<a[k]<<" ";
                k++;
            }
        for(int j=k;j<k+temp;j++){
                k++;
            }
    }

    return 0;
}
