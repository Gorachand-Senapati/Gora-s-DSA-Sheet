//recursion 
class Solution {
public:
  int f(int r, int c, vector<vector<int>>& grid){
    if(r ==0 && c==0) return grid[0][0];
    if(r<0 || c<0) return 1e9;
    int up = grid[r][c] + f(r-1,c,grid);
    int left = grid[r][c] +f(r,c-1,grid);
    return min(up,left);

  }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        return f(m-1,n-1,grid);
    }
};

//memoization
class Solution {
public:
  int f(int r, int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(r ==0 && c==0) return grid[0][0];
    if(r<0 || c<0) return 1e9;
    if(dp[r][c] != -1) return dp[r][c];
    int up = grid[r][c] + f(r-1,c,grid,dp);
    int left = grid[r][c] +f(r,c-1,grid,dp);
    return dp[r][c]= min(up,left);

  }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));//for memo
        return f(m-1,n-1,grid,dp);
    }
};

//Tabuliation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));//for tabu
         
         for(int r =0;r<m;r++){
            for(int c=0;c<n;c++){
                 if(r ==0 && c==0) dp[0][0]=grid[0][0];
                 else{
                   //calculate form top
                   int up = grid[r][c];
                   if(r>0) up+= dp[r-1][c];
                   else up+=1e9;//which if border cross never min
                   //calculate form left
                   int left = grid[r][c];
                   if(c >0) left+= dp[r][c-1];
                   else left +=1e9;//which if border cross never min

                   dp[r][c]= min(up, left);
                 }
            }
         }
         return dp[m-1][n-1];
    }
};

//space optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        vector<int>prev(n,0);//for tabu
         
         for(int r =0;r<m;r++){
            vector<int>curr(n,0);//current array
            for(int c=0;c<n;c++){
                 if(r ==0 && c==0) curr[0]=grid[0][0];
                 else{
                   //calculate form top
                   int up = grid[r][c];
                   if(r>0) up+= prev[c];//r-1 prev
                   else up+=1e9;//which if border cross never min
                   //calculate form left
                   int left = grid[r][c];
                   if(c >0) left+= curr[c-1];
                   else left +=1e9;//which if border cross never min

                  curr[c]= min(up, left);
                 }
            }
            prev = curr;
         }
         return prev[n-1];
    }
};