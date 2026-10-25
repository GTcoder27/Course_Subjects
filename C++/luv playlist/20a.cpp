// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3+10;
// int arr[N][N];
// int sum[N][N];

// int main()
// {
//     int n;
//     cin>>n; 
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>arr[i][j];
//             sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
//         }
//     }
//     int q;
//     cin>>q;
//     while(q--)
//     {
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         cout<<sum[c][d] - sum[a-1][b-1]<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10; 
int arr[N][N];
int sum[N][N];

int main() {
    int n;
    cin>>n; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] ; 
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<sum[c][d] - sum[a-1][b-1]<<endl;
    }
    return 0;
}


