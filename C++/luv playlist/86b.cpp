#include<bits/stdc++.h>
using namespace std;
// Leetcode Que. 200] Number of islands


void dfs(int i,int j,vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == '0' || grid[i][j] == '2') return;

    dfs(i-1,j,grid);
    dfs(i+1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
    
}


int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs( i, j, grid);   
                    count++;
                }
            }
        }
    return count;
}




int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    

    return 0;
}











