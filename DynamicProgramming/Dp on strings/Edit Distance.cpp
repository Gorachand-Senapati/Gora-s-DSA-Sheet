//recursion
class Solution {
public:
    int f(int i, int j, string &word1, string &word2){
        //base case if any one exhausted then other where need this much operation
        if(i < 0) return j+1;//if s1 exhauted;
        if(j < 0) return i+1;//if s2 exhauted;
        //if match char
        if(word1[i] == word2[j]){
            return 0 + f(i-1,j-1,word1,word2);
        }else{//replace , delte, insert
           return  1 + min(f(i-1,j-1,word1,word2), min(f(i-1,j,word1,word2), f(i,j-1,word1,word2)));
        }
    }
    int minDistance(string word1, string word2) {
        int n= word1.size(), m= word2.size();
        return f(n-1, m-1,word1,word2);
    }
};

//memoization
class Solution {
public:
    int f(int i, int j, string &word1, string &word2,vector<vector<int>>&dp){
        //base case if any one exhausted then other where need this much operation
        if(i < 0) return j+1;//if s1 exhauted;
        if(j < 0) return i+1;//if s2 exhauted;
        //if match char
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j]=  0 + f(i-1,j-1,word1,word2,dp);
        }else{//replace , delte, insert
           return dp[i][j] = 1 + min(f(i-1,j-1,word1,word2,dp), 
           min(f(i-1,j,word1,word2,dp), f(i,j-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n= word1.size(), m= word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1, m-1,word1,word2,dp);
    }
};

//memoization slight optimization not use i = -1 here i==0 is the base case
class Solution {
public:
    int f(int i, int j, string &word1, string &word2,vector<vector<int>>&dp){
        //base case if any one exhausted then other where need this much operation
        if(i == 0) return j;//if s1 exhauted;
        if(j == 0) return i;//if s2 exhauted;
        //if match char
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]){
            return dp[i][j]=  0 + f(i-1,j-1,word1,word2,dp);
        }else{//replace , delte, insert
           return dp[i][j] = 1 + min(f(i-1,j-1,word1,word2,dp), 
           min(f(i-1,j,word1,word2,dp), f(i,j-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n= word1.size(), m= word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n, m,word1,word2,dp);
    }
};

//tabulation
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int n= s1.size(), m= s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //base case 
        for(int i=0;i<=n;i++)dp[i][0]=i;//when j exhausted
        for(int j=1;j<=m;j++)dp[0][j]=j;//when i exhausted if j=0 not create any problem
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }else{//replace, delete, insert
                    dp[i][j] = 1+  min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};


//space optimization
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int n= s1.size(), m= s2.size();
        vector<int>prev(m+1,0), curr(m+1,0);
        //base case 
        for(int j=0;j<=m;j++)prev[j]=j;//when i exhausted
        
        for(int i=1;i<=n;i++){
            curr[0]= i; //when j exhausted another a base case
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 0 + prev[j-1];
                }else{//replace, delete, insert
                    curr[j] = 1+  min(prev[j-1], min(prev[j],curr[j-1]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};