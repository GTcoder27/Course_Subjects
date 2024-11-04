#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {176, 79, 34, 60, 92, 11, 41, 114};
    int ans = 0,hp = 50,total = 0, no_cyl = 200;
    cout<<"Seek operations sequence : \n";
    for(auto i:v)
    {
        cout<<i<<endl; 
    }
    total += abs(v[0] - hp);
    for(int i=0;i<(v.size()-1);i++){
        total += abs(v[i]-v[i+1]);
    }
    cout<<"Total No of seek movement : "<<total;
    return 0;
}