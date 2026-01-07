//recursion
class Solution {
public:
   int f(int r, int c, vector<vector<int>>& triangle){
    int m = triangle.size();
    if(r == m-1) return triangle[m-1][c];
    int down = triangle[r][c] + f(r+1,c, triangle);
    int diag = triangle[r][c] + f(r+1,c+1, triangle);
    return min(down, diag);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(0,0, triangle);
    }
};

//memoization
class Solution {
public:
   int f(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(r == triangle.size()-1) return triangle[r][c];
    if(dp[r][c] != -1) return dp[r][c];
    int down = triangle[r][c] + f(r+1,c, triangle, dp);
    int diag = triangle[r][c] + f(r+1,c+1, triangle,dp);
    return dp[r][c] = min(down, diag);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
         int m = triangle.size();
          vector<vector<int>>dp(m,vector<int>(m,-1));//for memo
        return f(0,0, triangle,dp);
    }
};

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
          vector<vector<int>>dp(n,vector<int>(n,0));//for memo
        //base case for last row
        for(int i=0;i<n;i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        //so now start from n-2 to 0 row
        for(int r = n-2; r>=0;r--){
            for(int c = r;c>=0;c--){//c= total i means 4 no row 4 size col
               int down = triangle[r][c] +dp[r+1][c];
               int diag = triangle[r][c] +dp[r+1][c+1];
               dp[r][c] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};

//space optimisation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
        //   vector<vector<int>>dp(n,vector<int>(n,0));//for memo
        vector<int>front(n,0);
        //base case
        for(int i=0;i<n;i++){
           front[i] = triangle[n-1][i];
        }
        //so now start from n-2
        for(int r = n-2; r>=0;r--){
             vector<int>curr(n,0);
            for(int c = r;c>=0;c--){//c= total i means 4 no row 4 size col
               int down = triangle[r][c] + front[c];
               int diag = triangle[r][c] + front[c+1];
               curr[c] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};