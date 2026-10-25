#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

int vis[8][8];
int lev[8][8];


int getX(string s){
    return s[0] - 'a';
}
int getY(string s){
    return s[1] - '1';
}

bool isValid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

vector<pair<int,int>> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

int bfs(string source,string dest){
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pair<int,int>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY] = 1;
    lev[sourceX][sourceY] = 0;

    while(!q.empty()){
        pair<int,int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();

        for(auto movement : movements ){
            int childX = movement.first + x;
            int childY = movement.second + y;
            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX,childY});
                lev[childX][childY] = lev[x][y] + 1;
                lev[childX][childY] = 1;
            }
        }
        if(lev[destX][destY] != INF){
            break;
        }
    }

    return lev[destX][destY];
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            lev[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        reset();
        string s1,s2;
        cin>>s1>>s2; 
        cout<<bfs(s1,s2);
    }
    




    return 0;
}

// input 
// 3 
// a1 h8 
// a1 c2 
// h8 c3










