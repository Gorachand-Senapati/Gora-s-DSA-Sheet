
//recursion

class Solution {
  public:
    int f(int r, int c,vector<vector<int>>& mat, int m){
        //base case
        if(c<0 || c >= m) return -1e8;//for maximum give intmin
        if(r ==0) return mat[0][c];
        //explore all path
        int below = mat[r][c] + f(r-1,c, mat,m);
        int left = mat[r][c] + f(r-1,c-1, mat,m);
        int right = mat[r][c] + f(r-1,c+1, mat,m);
        
        return max(below, max(left,right));
        
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int maxi = -1e8;
        for(int col =0;col<m;col++){
            maxi = max(maxi,f(n-1,col,mat, m));//start from last row to first
        }
        return maxi;
    }
};

//memoisation

class Solution {
  public:
    int f(int r, int c,vector<vector<int>>& mat, int m,  vector<vector<int>>&dp){
        //base case
        if(c<0 || c >= m) return -1e8;//for maximum give intmin
        if(r ==0) return mat[0][c];
        if(dp[r][c] != -1) return dp[r][c];
        //explore all path
        int below = mat[r][c] + f(r-1,c, mat,m,dp);
        int left = mat[r][c] + f(r-1,c-1, mat,m,dp);
        int right = mat[r][c] + f(r-1,c+1, mat,m,dp);
        
        return dp[r][c] = max(below, max(left,right));
        
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi = -1e8;
        for(int col =0;col<m;col++){
            maxi = max(maxi,f(n-1,col,mat, m, dp));//start from last row to first
        }
        return maxi;
    }
};

//tabulation 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();//row and col is same size
        vector<vector<int>>dp(n,vector<int>(n,0));//0 initialise
        for(int i =0;i<n;i++){//for col traversing for base case
           dp[0][i]= matrix[0][i];
        }
        for(int r=1; r<n;r++){
            for(int c=0;c<n;c++){
                int below = matrix[r][c] + dp[r-1][c];
                int left = 1e9;//this line need 
                if(c >0) left = matrix[r][c] + dp[r-1][c-1];
                int right = 1e9;////this line need 
                if(c < n-1) right = matrix[r][c] + dp[r-1][c+1];
                dp[r][c] = min(below, min(left,right));
            }
        }
        int mini = dp[n-1][0];
        for(int i=1;i<n;i++){
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};

//space optimise
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();//row and col is same size
        vector<int>prev(n,0),curr(n,0);//0 initialise
        for(int i =0;i<n;i++){//for col traversing for base case
           prev[i]= matrix[0][i];
        }
        for(int r=1; r<n;r++){
            for(int c=0;c<n;c++){
                int below = matrix[r][c] + prev[c];
                int left = 1e9;//this line need 
                if(c >0) left = matrix[r][c] + prev[c-1];
                int right = 1e9;////this line need 
                if(c < n-1) right = matrix[r][c] + prev[c+1];
                curr[c] = min(below, min(left,right));
            }
            prev = curr;
        }
        int mini = prev[0];
        for(int i=1;i<n;i++){
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};