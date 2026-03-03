//recursion TC= O
class Solution {
public:
   bool solve(int start, string &s, unordered_set<string>&st){
     if(start == s.size()) return true;// if word finish
     //cut the string
     for(int end =start+1;end<=s.size();end++){
        string part = s.substr(start,end-start);//substring(0,2)=le example
        if(st.count(part)) {
            if(solve(end,s,st)){
                return true;
            }
        }
     }
     return false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
         return solve(0,s,st);
    }
};

//DP MEMOIZATION TC= O(N^2) SC= O(N)
class Solution {
public:
   bool solve(int start, string &s, unordered_set<string>&st,vector<int>&dp){
     if(start == s.size()) return true;// if word finish
     //cut the string
     if(dp[start] != -1) return dp[start];
     for(int end =start+1;end<=s.size();end++){
        string part = s.substr(start,end-start);//substring(0,2)=le example
        if(st.count(part)) {
            if(solve(end,s,st,dp)){
                return dp[start]= true;
            }
        }
     }
     return dp[start] = false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size(),-1);
         return solve(0,s,st,dp);
    }
};

//DP TABULATION TC= O(N^2) SC= O(N)
class Solution {
public:
   bool solve(int start, string &s, unordered_set<string>&st,vector<int>&dp){
     if(start == s.size()) return true;// if word finish
     //cut the string
     if(dp[start] != -1) return dp[start];
     for(int end =start+1;end<=s.size();end++){
        string part = s.substr(start,end-start);//substring(0,2)=le example
        if(st.count(part)) {
            if(solve(end,s,st,dp)){
                return dp[start]= true;
            }
        }
     }
     return dp[start] = false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool>dp(n+1,0);
         dp[0] = true;//st true base case
         for(int i=1;i<=n;i++){//end part length of the prefix
            for(int j=0;j<i;j++){//new start for word 
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
                
            }
         }
         return dp[n];
    }
};