#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print_vector(vector<int> &v)
{
    cout<<"size : "<<v.size()<<" "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl; 
}

// void print_vector(vector<pair<int,int>> v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i].first<<" "<<v[i].second<<endl;
//     }
//     cout<<endl;
// }


int main()
{
    cout<<"pair of vectors"<<endl;
    // vector<pair<int,int>> v = {{1,2},{3,4},{5,6}};
    vector<pair<int,int>> v ;
    int n ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    print_vector(v);

    
    cout<<"Array of vectors "<<endl;
    int N;
    cin>>N;
    vector<int> v[N];
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(int i=0;i<N;i++)
    {
        print_vector(v[i]);
    }


    cout<<"Vector of vectors "<<endl;
    int N;
    cin>>N;
    vector<vector<int>> v;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for(int i=0;i<v.size();i++)
    {
        print_vector(v[i]);
    }
    cout<<v[0][1];
    
    return 0;
}