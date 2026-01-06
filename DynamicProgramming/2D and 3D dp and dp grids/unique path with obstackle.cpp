// grid unique path 2
class Solution {
  public:
  int f(int r, int c,vector<vector<int>> &grid){
      //base case
      if(r >=0 && c >=0 && grid[r][c] == 1) return 0;//obstacle
       if(r==0 && c==0)return 1;
      if (r<0 || c<0) return 0;
      //for start from last so down- up , right = left
      int up = f(r-1,c,grid);
      int left = f(r,c-1,grid);
      return up + left;
      
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        return f(m-1,n-1,grid);
    }
};

//memoisation 
class Solution {
  public:
  int f(int r, int c,vector<vector<int>> &grid,vector<vector<int>>&dp){
      //base case
      if(r >=0 && c >=0 && grid[r][c] == 1) return 0;//obstacle
       if(r==0 && c==0)return 1;
      if (r<0 || c<0) return 0;
       if(dp[r][c] != -1) return dp[r][c];
      //for start from last so down- up , right = left
      int up = f(r-1,c,grid,dp);
      int left = f(r,c-1,grid,dp);
      return dp[r][c] = up + left;
      
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
          vector<vector<int>>dp(m, vector<int>(n,-1));//need n-1 & m-1 so n,m size dp array
        return f(m-1,n-1, grid,dp);
    }
};

//tabulisation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        //base case
        for(int r =0;r<m;r++){
            for(int c =0; c<n;c++){
                if(obstacleGrid[r][c] == 1) dp[r][c] = 0;//this line need befor because if starting is 1
                else if(r ==0 && c == 0) dp[r][c] =1;
                else{
                    int up =0, left =0;
                    if(r >0) up = dp[r-1][c];
                    if(c > 0) left = dp[r][c-1];
                    dp[r][c] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimisation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int>prev(n,0);
        //base case
        for(int r =0;r<m;r++){
             vector<int>curr(n,0);//current row
            for(int c =0; c<n;c++){
                if(obstacleGrid[r][c] == 1) curr[c] = 0;//this line need befor because if starting is 1
                else if(r ==0 && c == 0) curr[c] =1;
                else{
                    int up =0, left =0;
                    if(r >0) up = prev[c];//r-1 prev
                    if(c > 0) left = curr[c-1];
                    curr[c] = up + left;
                }
            }
            prev =curr;
        }
        return prev[n-1];
    }
};