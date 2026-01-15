//recursion 
class Solution {
public:
   int f(int idx1, int idx2,string text1, string text2){
    //base case when out of boundary
    if(idx1 < 0 || idx2 < 0) return 0;
    if(text1[idx1] == text2[idx2]){//if matches the char
      return 1 + f(idx1-1, idx2-1, text1,text2);
    }
    return 0 + max(f(idx1-1, idx2, text1,text2), f(idx1, idx2-1, text1,text2));
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
       return f(n-1,m-1, text1,text2);
    }
};

//memoization
class Solution {
public:
   int f(int idx1, int idx2,string &text1, string &text2, vector<vector<int>>&dp){
    //base case when out of boundary
    if(idx1 < 0 || idx2 < 0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(text1[idx1] == text2[idx2]){//if matches the char
      return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, text1,text2,dp);
    }
    return dp[idx1][idx2]= 0 + max(f(idx1-1, idx2, text1,text2,dp), f(idx1, idx2-1, text1,text2,dp));
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if(n==0 || m==0) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return f(n-1,m-1, text1,text2,dp);
    }
};
//memoization with shifted index
class Solution {
public:
   int f(int idx1, int idx2,string &text1, string &text2, vector<vector<int>>&dp){
    //base case when out of boundary
      if(idx1==0 || idx2==0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(text1[idx1-1] == text2[idx2-1]){//if matches the char
      return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, text1,text2,dp);
    }
    return dp[idx1][idx2]= 0 + max(f(idx1-1, idx2, text1,text2,dp), f(idx1, idx2-1, text1,text2,dp));
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
      
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return f(n,m, text1,text2,dp);
    }
};

//tabulation
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //base case when shifting
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        //parmeter change
        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]== s2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else dp[i][j]= 0 + max(dp[i-1][j], dp[i][j-1]);//need else
            }
        }
        return dp[n][m];
    }
};

//space optimization
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<int>prev(m+1,0), curr(m+1,0);
        //base case when shifting
        for(int i=0;i<=m;i++)prev[i] = 0;
        // for(int j=0;j<=m;j++)dp[0][j]=0;//not need col
        //parmeter change
        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]== s2[j-1]){
                    curr[j]= 1 + prev[j-1];
                }
                else curr[j]= 0 + max(prev[j], curr[j-1]);//need else
            }
            prev = curr;
        }
        return prev[m];
    }
};
