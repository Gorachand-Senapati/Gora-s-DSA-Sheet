class Solution {
private: 
   void bfs(int row, int col,vector<vector<char>>& grid, vector<vector<int>>& vis,
    int n, int m, int dr[], int dc[]){
    queue<pair<int, int>>q;
    vis[row][col]=1;
    q.push({row, col});
    while(!q.empty()){
        int r= q.front().first;
        int c=q.front().second;
        q.pop();
        //check neighbour row , neighbour col 
        for(int i=0;i<4;i++){
            int nr=r+dr[i], nc= c+dc[i];
             if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr, nc});
                }
        }
    }
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(), m= grid[0].size();//row col size define
        vector<vector<int>>vis(n, vector<int>(m,0));//make a visted and all are 0 now
        int cnt =0;
            int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1' && vis[r][c]==0){//if land and not visited
                cnt++;
                    bfs(r,c,grid,vis,n,m,dr,dc);
                }
            }
        }
        return cnt;
    }
};

//using dfs
class Solution {
private:
  void dfs(int r, int c, vector<vector<char>>& grid,
           vector<vector<int>>& vis, int n, int m, int dr[], int dc[]) {
      vis[r][c] = 1;

      for (int i = 0; i < 8; i++) { // now 8 directions
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
              !vis[nr][nc] && grid[nr][nc] == 'L') {
              dfs(nr, nc, grid, vis, n, m, dr, dc);
          }
      }
  }

public:
  int countIslands(vector<vector<char>>& grid) {
      int n = grid.size(), m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m, 0));
      int cnt = 0;

      // use 8-directional connectivity
      int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
      int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

      for (int r = 0; r < n; r++) {
          for (int c = 0; c < m; c++) {
              if (grid[r][c] == 'L' && vis[r][c] == 0) {
                  cnt++;
                  dfs(r, c, grid, vis, n, m, dr, dc);
              }
          }
      }
      return cnt;
  }
};
