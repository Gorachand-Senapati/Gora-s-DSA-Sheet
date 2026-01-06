// recursion TC = O(2 ^ n*m) SC= O(path length)= O(m-1*n-1) + O(n*m); O(n*m) for recursion stack space
class Solution {
  public:
  int f(int r, int c){
      //base case
      if(r==0 && c==0)return 1;
      if (r<0 || c<0) return 0;
      //for start from last so down- up , right = left
      int up = f(r-1,c);
      int left = f(r,c-1);
      return up + left;
  }
    int numberOfPaths(int m, int n) {
        // Code Here
        return f(m-1,n-1);
    }
};

//memoisation TC = O( n*m) SC= O(path length)= O(m-1 + n-1) + O(n*m); O(n*m) for recursion stack space & extra for dp array
class Solution {
  public:
  int f(int r, int c, vector<vector<int>>&dp){
      //base case
      if(r==0 && c==0)return 1;
      if (r<0 || c<0) return 0;
      //so before call check it value have in dp
      if(dp[r][c] != -1) return dp[r][c];
      //for start from last so down- up , right = left
      int up = f(r-1,c,dp);
      int left = f(r,c-1,dp);
      return dp[r][c] = up + left;
  }
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>>dp(m, vector<int>(n,-1));//need n-1 & m-1 so n,m size dp array
        return f(m-1,n-1, dp);
    }
};

//tabulisation  TC = O( n*m) SC= O(path length)= O(m-1 + n-1) + O(n*m) this is for dp array

class Solution {
  public:
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>>dp(m, vector<int>(n,0));//need n-1 & m-1 so n,m size dp array
        
        for(int r =0;r<m;r++){
            for(int c=0;c<n;c++){
                if( r==0 && c ==0) dp[r][c]=1;
                else{
                    int up =0, left = 0;
                    if(r >0) up = dp[r-1][c];
                    if(c > 0) left = dp[r][c-1];
                    dp[r][c]= up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimisation TC = O( n*m) SC= O(n)
class Solution {
  public:
    int numberOfPaths(int m, int n) {
        // Code Here
        // vector<vector<int>>dp(m, vector<int>(n,0));//need n-1 & m-1 so n,m size dp array
        vector<int>prev(n,0);
        for(int r =0;r<m;r++){
            vector<int>temp(n,0);//current row
            for(int c=0;c<n;c++){
                if( r==0 && c ==0) temp[c]=1;//current row change
                else{
                    int up =0, left = 0;
                    if(r >0) up = prev[c]; //r-1 = prev
                    if(c > 0) left = temp [c-1];//r = current row
                    temp[c]= up + left;//r = current row
                    
                }
            }
            prev= temp;//store the current now prev
        }
        return prev[n-1];//m-1 means prev
    }
};
