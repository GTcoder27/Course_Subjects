#include<bits/stdc++.h>
using namespace std;


int arraysum(int n,int arr[] )
{
    if(n<0)
    {
        return 0;
    }
    return arr[n]+arraysum(n-1,arr);
}

int digitsum(int n)
{
    if(n==0) return 0;
    return (n%10) + digitsum(n/10);
}


int main()
{
    // to find size of array
    // for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
    // {
    //     cout<<arr[i];
    // }


    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    // cout << arraysum(n-1,arr);

    int n;
    cin>>n;
    cout<<digitsum(n);


    return 0;
}