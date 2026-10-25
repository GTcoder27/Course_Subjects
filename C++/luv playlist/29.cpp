#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print_vector(vector<int> &v)
{
    cout<<"size of vector: "<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        // v.size() --> O(1)
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    // // We are assigning same address to both the variables.
    // int m = 20;
    // int &ptr= m; 
    // ptr++;
    // cout<<ptr<<endl<<m<<endl;
    // cout<<&ptr<<endl<<&m<<endl;

    // pair<int,string> p ;
    // // p = make_pair(2,"hello");
    // p = {2,"hello"};
    // cout<<p.first<<" "<<p.second<<endl;
    // pair<int,string> &p1 = p;
    // p1.second = "girish";
    // cout<<p1.first<<" "<<p1.second<<endl;
    // int a[] = {1,2,3};
    // int b[] = {2,3,4};
    // pair<int, int> p_array[3];
    // p_array[0] = {1,2};
    // p_array[1] = {3,4};
    // p_array[2] = {5,6};
    // swap(p_array[0],p_array[2]);
    // for(int i=0;i<3;i++)
    // {
    //     cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    // }



    cout<<endl<<"## Vectors ##"<<endl;



    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     int x;
    //     cin>>x;
    //     print_vector(v);
    //     v.push_back(x);
    // }
    // print_vector(v);

    // vector<int> v(10);
    vector<int> v(10,3);
    v.push_back(7);
    print_vector(v);
    v.pop_back();
    print_vector(v);
    
    vector<int> &v2 = v;
    v2.push_back(5);
    // print_vector(v2);
    // print_vector(v);








    
    return 0;
}