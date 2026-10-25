// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;



// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,k;
//         cin>>n>>k;
//         multiset<long long> bags;
//         for(int i = 0;i < n; i++)
//         {
//             long long candy_ct;
//             cin>>candy_ct;
//             bags.insert(candy_ct);
//         }
//         long long total_candies = 0;
//         for(int i = 0;i < k; i++)
//         {
//             auto last_it = (--bags.end());
//             long long candy_ct  = *last_it;
//             total_candies += candy_ct;
//             bags.erase(last_it);
//             bags.insert(candy_ct/2);
//         }
//         cout << total_candies << endl;
//     }



//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<long long> s;
    int n,k;
    int total = 0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    for(int i=0;i<k;i++)
    {
        auto it = --s.end();
        int temp2 = (*it)/2;
        total += (*it);
        s.erase(it);
        s.insert(temp2);
    }
    cout<<total;



    return 0;
}