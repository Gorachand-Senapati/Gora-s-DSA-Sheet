//recursion 
class Solution {
public:
   bool f(int i, int j, string &s, string &p){
    //base case if both exhausted true
    if(i < 0 && j<0) return true;
    if(j < 0 && i >=0)return false;//pattern finish but string exits
    if(i <0 && j >=0){
        for(int c = 0;c<= j;c++){
            if(p[c] != '*')return false;//if not * then false
        }
        return true;
    }
    //if match || p == ?return true
    if(s[i] == p[j] || p[j] == '?'){
        return f(i-1,j-1,s,p);
    }
    if(p[j] == '*'){//2 way 1. assume nothing 2. some sequece
      return f(i,j-1,s,p) || f(i-1,j,s,p);
    }
    return false;//if not match anything
   }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
       return f(n-1,m-1,s,p);
    }
};

//memoization
class Solution {
public:
   bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp){
    //base case if both exhausted true
    if(i < 0 && j<0) return true;
    if(j < 0 && i >=0)return false;//pattern finish but string exits
    if(i <0 && j >=0){
        for(int c = 0;c<= j;c++){
            if(p[c] != '*')return false;//if not * then false
        }
        return true;
    } //base case end
    if(dp[i][j] != -1) return dp[i][j];
    //if match || p == ?return true
    if(s[i] == p[j] || p[j] == '?'){
        return dp[i][j] = f(i-1,j-1,s,p,dp);
    }
    if(p[j] == '*'){//2 way 1. assume nothing 2. some sequece
      return dp[i][j] = f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);
    }
    return dp[i][j]  = false;//if not match anything
   }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return f(n-1,m-1,s,p,dp);
    }
};

//memoization slight optimization not use i = -1 here i==0 is the base case
class Solution {
public:
   bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp){
    //base case if both exhausted true
    if(i == 0 && j==0) return true;
    if(j == 0 && i > 0)return false;//pattern finish but string exits
    if(i  == 0 && j > 0){
        for(int c = 1;c<= j;c++){
            if(p[c-1] != '*')return false;//if not * then false
        }
        return true;
    } //base case end
    if(dp[i][j] != -1) return dp[i][j];
    //if match || p == ?return true
    if(s[i-1] == p[j-1] || p[j-1] == '?'){
        return dp[i][j] = f(i-1,j-1,s,p,dp);
    }
    if(p[j-1] == '*'){//2 way 1. assume nothing 2. some sequece
      return dp[i][j] = f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);
    }
    return dp[i][j]  = false;//if not match anything
   }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return f(n,m,s,p,dp);
    }
};

//tabulation
class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base case
         dp[0][0] = true;
        for(int i=1;i<=n;i++)dp[i][0] = false;//if pattern exhausted
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int c = 1;c<= j;c++){
              if(pat[c-1] != '*'){
                flag = false;
                break;
               };//if not * then false
            }
             dp[0][j] = flag;
        }
        //changing parameter
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(txt[i-1] == pat[j-1] || pat[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(pat[j-1] == '*'){
                    dp[i][j]= dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j]= false;
                }
            }
        }
        return dp[n][m];
    }
};

//space optimization
class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<bool>prev(m+1,false),curr(m+1,false);
        //base case
         prev[0] = true;
        // for(int i=1;i<=n;i++)dp[i][0] = false;//if pattern exhausted
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int c = 1;c<= j;c++){
              if(pat[c-1] != '*'){
                flag = false;
                break;
               };//if not * then false
            }
             prev[j] = flag;
        }
        //changing parameter
        for(int i=1;i<=n;i++){
            curr[0]=false;//when new row created st is false another base case
            for(int j=1;j<=m;j++){
                if(txt[i-1] == pat[j-1] || pat[j-1] == '?'){
                    curr[j] = prev[j-1];
                }else if(pat[j-1] == '*'){
                   curr[j]= prev[j] || curr[j-1];
                }else{
                    curr[j]= false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};