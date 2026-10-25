#include<bits/stdc++.h>
using namespace std;
main()
{
    // auto sum = [](int x,int y){return x+y;};
    // cout<<sum(3,5);

    vector<int> v = {3,4,5};
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
    cout<<any_of(v.begin(),v.end(),[](int x){return x%2==0;})<<endl;
    cout<<none_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;


    



    
    return 0;
}