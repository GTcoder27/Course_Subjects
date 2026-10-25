#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // sort(a,a+n);  // Intro Sort = Quick Sort + Heap Sort + Insertion Sort
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }


    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());  // Intro Sort = Quick Sort + Heap Sort + Insertion Sort
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }




    return 0;
}