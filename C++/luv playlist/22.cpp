#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 +10 ;
long long int arr[N];

int main()
{
    int n,t;
    cin>>n>>t;
    while(t--)
    {
        int a,b,x;
        cin>>a>>b>>x;
        arr[a] += x ;
        arr[b+1] -= x ;
    }
    for(int i=1;i<=N;i++)
    {
        arr[i] += arr[i-1]; 
    }
    long long max = -1;
    for(int i=1;i<=N;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    cout<<max<<endl;


    return 0;
}