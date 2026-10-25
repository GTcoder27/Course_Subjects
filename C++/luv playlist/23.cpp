#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10 ;
int hash[N][26];

int main()
{
    // some mistake is there 
    int t ;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<26;j++)
            {
                hash[i][j] = 0;
            }
        }
        int n,q;
        cin>>n>>q;
        string s ;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            hash[i+1][s[i]-'a']++;  
        }
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=n;j++)
            {
                hash[j][i] += hash[j-1][i];
            }
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int oddCount = 0;
            for(int i=0;i<26;i++)
            {
                int charCt = hash[r][i] - hash[l-1][i];
                if(charCt % 2 != 0)
                {
                    oddCount++;
                }
            }
            if(oddCount > 1)
            {
                cout<<"NO\n";
            }
            else 
            {
                cout<<"YES\n";
            }
        }
    }


    return 0;
}