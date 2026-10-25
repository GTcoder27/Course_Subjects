#include <bits/stdc++.h>
using namespace std;
// Edit Distance (Leetcode 73)

int lcs(int n1, int n2, string s1, string s2, vector<vector<int>> &dp)
{

    for (int i = 0; i < n1 + 1; i++)
    {
        for (int j = 0; j < n2 + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            if (j == 0)
            {
                dp[i][j] = i;
            }
        }
    }

    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 1; j < n2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int add = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                int rep = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(add, min(del, rep));
            }
        }
    }

    return dp[n1][n2];
}

int main()
{
    string word1, word2;
    cin>>word1>>word2;



    int n1 = word1.size();
    int n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    cout << lcs(n1, n2, word1, word2, dp) << endl;

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            cout<<dp[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}


// input 
// intention execution


// output




