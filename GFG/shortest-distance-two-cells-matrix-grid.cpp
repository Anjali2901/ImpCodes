// https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/

#include <bits/stdc++.h>
using namespace std;
#define N 4
#define M 4
struct item {
    public :
    int row,col,dist;
    item(int r,int c,int d){
        row = r;
        col = c;
        dist = d;
    }
};
bool issafe(int i,int j,char grid[N][M],bool vis[N][M]){
    if(i<0 || i>=N || j<0 || j>=M || vis[i][j]==true )
        return false;
    else
        return true;
}
int minDistance(char grid[N][M]) {
    item *s = new item(0,0,0);
    bool vis[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j] == '0')
                vis[i][j] = true;
            else
                vis[i][j] = false;
                
            if(grid[i][j] == 's'){
                s->row = i;
                s->col = j;
            }
        }
    }
    int xx[] = {1,0,-1,0};
    int yy[] = {0,1,0,-1};
    queue<item*> q ;
    q.push(s);
    vis[s->row][s->col] = true;
    while(!q.empty()) {
        item *p = q.front();
        q.pop();
        if(grid[p->row][p->col] == 'd')
          return p->dist;
        for(int i=0;i<4;i++){
            int x = p->row+xx[i], y = p->col+yy[i];
            if(issafe(x,y,grid,vis)){
              q.push(new item(x,y,p->dist+1));
              vis[x][y] = true;
            }
        }
    }
}
int main() {
    char grid[N][M] = { { '0', '*', '0', 's' }, 
                        { '*', '0', '*', '*' }, 
                        { '0', '*', '*', '*' }, 
                        { 'd', '*', '*', '*' } }; 
  
    cout << minDistance(grid); 
    return 0; 
}
