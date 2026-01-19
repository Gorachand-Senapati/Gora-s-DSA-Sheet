//recursion 
class Solution {
public:
   int f(int i, int j, string s, string t){
    //base case 1. if all match of s2 j<0 and if out of bound the i=-1 but still j exitst
    if(j <0) return 1;
    if(i < 0) return 0;
    if(s[i] == t[j]){//if match
        return f(i-1,j-1,s,t) + f(i-1,j,s,t);//both reduce + not happy with current i
    }else{
        return f(i-1, j,s,t);
    }

   }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        return f(n-1,m-1,s,t);
    }
};

//memoization
class Solution {
public:
   int f(int i, int j, string s, string t,vector<vector<int>>&dp){
    //base case 1. if all match of s2 j<0 and if out of bound the i=-1 but still j exitst
    if(j <0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){//if match
        return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);//both reduce + not happy with current i
    }else{
        return dp[i][j]=  f(i-1, j,s,t,dp);
    }

   }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1,m-1,s,t,dp);
    }
};
//memoization slight optimization not use i = -1 here i==0 is the base case
class Solution {
public:
   int f(int i, int j, string s, string t,vector<vector<int>>&dp){
    //base case 1. if all match of s2 j<0 and if out of bound the i=-1 but still j exitst
    if(j == 0) return 1;
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]){//if match
        return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);//both reduce + not happy with current i
    }else{
        return dp[i][j]=  f(i-1, j,s,t,dp);
    }

   }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));//here -1 =0 and n= n-1
        return f(n,m,s,t,dp);
    }
};

//tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>>dp(n+1, vector<double>(m+1, 0));//here -1 =0 and n= n-1 need double to avoid overflow
        //base case
        for(int i=0;i<=n;i++)dp[i][0] = 1;
        for(int j=1;j<=m;j++)dp[0][j] = 0;
        //bottom up
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else {
                   dp[i][j]=  dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

//space optimization 2 arrays
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double>prev(m+1,0), curr(m+1,0);//here -1 =0 and n= n-1 
        //base case just 1st col is the 1 for prev and curr bcz when i=0 all j=0 is 1 when j=0 then ans=1
        prev[0]=curr[0]=1;
        
        //bottom up
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }else {
                   curr[j]=  prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

//space optimization 1 array
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double>dp(m+1,0);//here -1 =0 and n= n-1
        //base case just 1st col is the 1 for prev and curr
        dp[0]= 1;
        //bottom up
        for(int i=1;i<=n;i++){
            // for(int j=1;j<=m;j++){ it go now m to 1 because if in place change need the prev val+cur
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return dp[m];
    }
};