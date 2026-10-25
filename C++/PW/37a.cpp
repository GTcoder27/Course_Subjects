#include <bits/stdc++.h>
using namespace std;


void generate_path(int i,int j,int m, int n, int &paths){
    if(m==i && n==j){
        paths++;
        return;
    }
    if(m<i || n<j) return;

    generate_path(i+1,j,m,n,paths); // not taking ith path (going bottom)

    generate_path(i,j+1,m,n,paths); // taking ith paths (going right)
}

int main() {
    
    int m,n;
    cin>>m>>n;
    int paths = 0;
    generate_path(1,1,m,n,paths);
    cout<<paths;

    return 0;
}


// input 
// 3 3

// output
// 6