//memoization TC = O(n) SC= O(n)+O(n)
class Solution {
public:
   int f(int i, string &s,int n, vector<int>&dp){
    //base case

    if(i== n ) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    if(s[i] != '0'){
        ans +=f(i+1,s,n,dp);
    }
    if(i+1 < n && (s[i] == '1' || s[i] =='2' && s[i+1] <= '6')){
        ans+= f(i+2,s,n,dp);
    }
     return dp[i]= ans;
   }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,s,n,dp);
    }

};

//tabulation
class Solution {
public:
   
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[n] = 1;
        
        for(int i = n-1;i>=0;i--){
            
             if(s[i] != '0'){
            dp[i]+=dp[i+1];
            }
            if(i+1 < n && (s[i] == '1' || s[i] =='2' && s[i+1] <= '6')){
                dp[i]+= dp[i+2];
             }
        }
        return dp[0];
    }

};
//space optimisation
class Solution {
public:
   
    int numDecodings(string s) {
        int n = s.size();
        
       int dp1 = 1, dp=0, dp2=0;
        
        for(int i = n-1;i>=0;i--){
            
             if(s[i] != '0'){
            dp+=dp1;
            }
            if(i+1 < n && (s[i] == '1' || s[i] =='2' && s[i+1] <= '6')){
                dp+= dp2;
             }
             dp2= dp1;
             dp1= dp;
             dp=0;
        }
        return dp1;
    }

};