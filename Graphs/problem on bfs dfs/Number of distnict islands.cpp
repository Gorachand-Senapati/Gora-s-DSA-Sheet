// User function Template for C++

class Solution {
private: 
   void dfs(int r, int c,vector<vector<int>>& vis,vector<vector<int>>& grid,
   vector<pair<int, int>>&vec, int r0, int c0, int n, int m){
       vis[r][c]=1;
       vec.push_back({r-r0,c-c0});//row- baserow that find coordinat
       int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
        for(int i=0;i<4;i++){
            int nr= r+dr[i], nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]== 1){
                dfs(nr, nc,vis,grid,vec,r0,c0,n,m);
            }
        }
   }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));//vis array
        set<vector<pair<int,int>>>st;//store the coordinate of identical vector so set sz is the ans 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]== 1){//not vist and land
                    vector<pair<int, int>>vec;//store the list of coordinate
                    dfs(i, j, vis, grid, vec,i,j,n, m);//last i,j is the  base row, base col index
                    st.insert(vec);
                }
            }
        }
        return st.size();//this is ans how much identical
    }
};