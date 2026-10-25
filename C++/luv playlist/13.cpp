#include<bits/stdc++.h>
using namespace std;
char upper(char c)
{
    return ('A'+(c-'a'));
}
int power(int n)
{
    int pro = 1 ;
    if(n==0)
    {
        return 1;
    }
    else
    {
        while(n--)
        {   
            pro = pro * 2;
        }
        return pro;
    }
}


main()
{
    
    // while(1)
    // {
    //     string s;
    //     cin>>s;
    //     if(s.size() == 0)
    //     {
    //         break;
    //     }
    //     for(int i=0;i<s.size();i++)
    //     {
    //         s[i] = upper(s[i]);
    //     }
    //     cout<<s<<endl;
    // }

    // int n;
    // cin>>n;
    // while(n--)
    // {
    //     int a;
    //     cin>>a;
    //     int pro = 1;
    //     for(int i=0;i<a;i++)
    //     {
    //         int no;
    //         cin>>no;
    //         pro = pro*no;
    //     }
    //     int sig = pro%10;
    //     if(sig==2 || sig==3 || sig==5)
    //     {
    //         cout<<"YES";
    //     }
    //     else 
    //     {
    //         cout<<"NO";
    //     }
    // }

    // int n;
    // cin>>n;
    // int sum = 0,dig,count = 0;
    // while(n!=0)
    // {
    //     dig = n % 10;
    //     n = n/10;
    //     dig = dig * power(count);
    //     sum = sum + dig;
    //     count++;
    // }
    // cout<<sum;









}