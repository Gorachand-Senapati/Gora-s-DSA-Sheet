class Solution {
 void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>&vis,
  int m, int n, int dr[], int dc[]){
    vis[row][col] = 1;
    for(int i=0;i<4;i++){
        int nr = row + dr[i];//next row assign
        int nc = col + dc[i];//next col assign
        if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] == 1){
            dfs(nr, nc, grid, vis,m,n,dr, dc);
        }
    }
  }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size();//row size
        int n= grid[0].size();//col size
         vector<vector<int>>vis(m, vector<int>(n,0));//make a vis array assing 0
          int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
        //now traverse all boundary char i- row , j- col
        for(int j=0;j<n;j++){//search for 1st and last row all coll
            if(grid[0][j] == 1){//1st row 
                dfs(0,j,grid, vis, m,n, dr, dc);
            }
            if(grid[m-1][j] == 1){//last row 
                dfs(m-1,j,grid, vis, m,n, dr, dc);
            }
        }
        for(int i=0;i<m;i++){//search for 1st and last col and its all rows
            if(grid[i][0] == 1){//1st col
                dfs(i,0,grid, vis, m,n, dr, dc);
            }
            if(grid[i][n-1] == 1){//last col
                dfs(i,n-1,grid, vis, m,n, dr, dc);
            }
        }
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};//using dfs

//using BFS
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m = grid.size();//row size
        int n= grid[0].size();//col size
        queue<pair<int, int>>q;//make r, c in que
        int vis[m][n]= {0};
        //now check boundary if has 1 then push it que and make vis
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //first row, first col, first row, first col
                if(i ==0 || j==0 || i==m-1 || j== n-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j]= 1;
                    }
                }
            }
        }
        int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc] ==0 && grid[nr][nc]==1){
                    q.push({nr, nc});
                    vis[nr][nc]=1;
                }
            }
        }//bfs traverse
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;//if 1 and not visited
                }
            }
        }
        return cnt;
    }
};
