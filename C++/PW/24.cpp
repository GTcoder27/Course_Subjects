#include<bits/stdc++.h>
using namespace std;
// spiral matrix 

int main()
{
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int top = 0,bottom = n-1,left = 0,right = m-1;
    int dir = 0;
    cout<<"ans \n";
    while(top <= bottom && left <= right){

        if(dir == 0){
            for(int i=left;i<=right;i++){
                cout<<v[top][i]<<" ";
            }
            top++;
            dir = (dir+=1)%4;
        }
        else if(dir == 1){
            for(int i=top;i<=bottom;i++){
                cout<<v[i][right]<<" ";
            }
            right--;
            dir = (dir+=1)%4;
        }
        else if(dir == 2){
            for(int i=right;i>=left;i--){
                cout<<v[bottom][i]<<" ";
            }
            bottom--;
            dir = (dir+=1)%4;
        }
        else if(dir == 3){
            for(int i=bottom;i>=top;i--){
                cout<<v[i][left]<<" ";
            }
            left++;
            dir = (dir+=1)%4;
        }
    }
    
    

    return 0;
}


// input 
// 4 4 
// 1 2 3 4  
// 12 13 14 5
// 11 16 15 6 
// 10 9 8 7
