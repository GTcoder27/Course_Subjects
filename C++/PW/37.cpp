#include <bits/stdc++.h>
using namespace std;

vector<int> subsets_sum;

void generate(vector<int> v, int i, int sum){
    if(i == v.size()){
        subsets_sum.push_back(sum);
        return;
    }

    generate(v,i+1,sum); // not taking ith digit

    generate(v,i+1,sum+v[i]); // taking ith digit
}

int main() {
    
    vector<int> v = {2,3};
    generate(v,0,0);
    sort(subsets_sum.begin(),subsets_sum.end());
    for(auto i:subsets_sum){
        cout<<i<<" ";
    }
    


    return 0;
}
