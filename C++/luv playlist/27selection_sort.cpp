#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"unsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        int small = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j] < arr[small])
            {
                small = j;
            }
        }
        // int temp;
        // temp =  arr[small];
        // arr[small] = arr[i];
        // arr[i] = temp;
        swap(arr[i],arr[small]);
    }
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}