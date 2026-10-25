#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> divisors[N];

int main()
{
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
    for(int i=0;i<10;i++){
        cout<<i<<" = "; 
        for(int j:divisors[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }





    return 0;
}
