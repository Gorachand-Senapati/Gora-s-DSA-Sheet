//recursion
class Solution {
public:
  int f (int r, int c1, int c2, vector<vector<int>>& grid,int m,int n){
    //base case 1.boundry 2. destination
    if(c1< 0 || c1 >=n || c2 <0 || c2 >= n) return -1e9;
    if(r == m-1){//reach last row
       if(c1 == c2) return grid[r][c1];
       else return grid[r][c1] + grid[r][c2];
    }
    //total 9 combos explore all path both simulataniously 
    int maxi = -1e9;
      for(int i=-1;i<=1;i++){//alice
        for(int j=-1;j<=1;j++){//bob
           int value = 0;
           if(c1 == c2) value = grid[r][c1];//if same cell
           else value = grid[r][c1] + grid[r][c2];
           value+= f(r+1, c1+i, c2+j, grid, m,n);//next recursion for all path
           maxi = max(maxi, value);
        }
      }
      return maxi;
  }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return f(0,0,n-1, grid,m,n);//row,alice st,bob st coloumn
    }
};

//memoization 
class Solution {
public:
  int f (int r, int c1, int c2, vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>&dp){
    //base case 1.boundry 2. destination
    if(c1< 0 || c1 >=n || c2 <0 || c2 >= n) return -1e9;
    if(r == m-1){//reach last row
       if(c1 == c2) return grid[r][c1];
       else return grid[r][c1] + grid[r][c2];
    }
    //before function call check dp value
    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
    //total 9 combos explore all path both simulataniously 
    int maxi = -1e9;
      for(int i=-1;i<=1;i++){//alice
        for(int j=-1;j<=1;j++){//bob
           int value = 0;
           if(c1 == c2) value = grid[r][c1];//if same cell
           else value = grid[r][c1] + grid[r][c2];
           value+= f(r+1, c1+i, c2+j, grid, m,n,dp);//next recursion for all path
           maxi = max(maxi, value);
        }
      }
      return dp[r][c1][c2] = maxi;
  }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //take a 3d dp[r][c1][c2]
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n,-1)));//3d
        return f(0,0,n-1, grid,m,n,dp);//row,alice st,bob st coloumn
    }
};

class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //take a 3d dp[r][c1][c2]
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n,0)));//3d
        //base case
        // dp last row value
        for(int c1 =0;c1<n;c1++){
            for(int c2 =0;c2<n;c2++){
                if(c1 == c2) dp[m-1][c1][c2]= grid[m-1][c1];//if alice and bob same cell
                else dp[m-1][c1][c2]= grid[m-1][c1] + grid[m-1][c2];
            }
        }
        //now from last before row to 1st row 
        for(int r= m-2;r>=0;r--){
            for(int c1 =0;c1<n;c1++){
                for(int c2 =0;c2<n;c2++){
                    int maxi = -1e9;
                   for(int i=-1;i<=1;i++){//alice
                      for(int j=-1;j<=1;j++){//bob
                         int value = 0;
                            if(c1 == c2) value = grid[r][c1];//if same cell
                           else value = grid[r][c1] + grid[r][c2];
                           if(c1+i >= 0 && c1+i <n && c2+j >= 0 && c2+j < n) 
                               value+= dp[r+1][c1+i][c2+j];//next recursion for all path
                            else value+= -1e9;
                          maxi = max(maxi, value);
                        }
                    }
                    dp[r][c1][c2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};

//space optimise
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>front(n,vector<int>(n,0));
        vector<vector<int>>curr(n,vector<int>(n,0));
        //base case
        // dp last row value
        for(int c1 =0;c1<n;c1++){
            for(int c2 =0;c2<n;c2++){
                if(c1 == c2) front[c1][c2]= grid[m-1][c1];//if alice and bob same cell
                else front[c1][c2]= grid[m-1][c1] + grid[m-1][c2];
            }
        }
        //now from last before row to 1st row 
        for(int r= m-2;r>=0;r--){
            for(int c1 =0;c1<n;c1++){
                for(int c2 =0;c2<n;c2++){
                    int maxi = -1e9;
                   for(int i=-1;i<=1;i++){//alice
                      for(int j=-1;j<=1;j++){//bob
                         int value = 0;
                            if(c1 == c2) value = grid[r][c1];//if same cell
                           else value = grid[r][c1] + grid[r][c2];
                           if(c1+i >= 0 && c1+i <n && c2+j >= 0 && c2+j < n) 
                               value+= front[c1+i][c2+j];//next recursion for all path
                            else value+= -1e9;
                          maxi = max(maxi, value);
                        }
                    }
                    curr[c1][c2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][n-1];
    }
};