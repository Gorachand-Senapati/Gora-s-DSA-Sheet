//recursion
class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string &s){
        //base case
        int n = s.size();
        if(i==n) return 0;
        int minCuts = INT_MAX;
        //string go from i ... j
        for(int j=i;j<n;j++){//start forward partitioning
            if(isPalindrome(i,j,s) == true){
                int cuts = 1 + f(j+1,s);
                minCuts = min(minCuts,cuts);
            }
        }
        return minCuts;
    }
    int minCut(string s) {
        return f(0,s) -1;//-1 because when all are different need n cuts so a b c if 2 cut then ans find
    }
};

//memoization
class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n, string &s, vector<int>&dp){
        //base case
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCuts = INT_MAX;
        //string go from i ... j
        for(int j=i;j<n;j++){//start forward partitioning
            if(isPalindrome(i,j,s) == true){
                int cuts = 1 + f(j+1,n,s,dp);
                minCuts = min(minCuts,cuts);
            }
        }
        return dp[i] = minCuts;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp) -1;//-1 because when all are different need n cuts so a b c if 2 cut then ans find
    }
};

//tabulation
class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;//base case
        for(int i=n-1;i>=0;i--){
          int minCuts = INT_MAX;
          //string go from i ... j
          for(int j=i;j<n;j++){//start forward partitioning
              if(isPalindrome(i,j,s) == true){
                  int cuts = 1 + dp[j+1];//so need n+1
                  minCuts = min(minCuts,cuts);
              }
          }
        dp[i] = minCuts;
        }
        return dp[0] -1;//-1 because when all are different need n cuts so a b c if 2 cut then ans find
    }
};

//TC= O(n^2) SC= O(n^2)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // 1) Precompute palindrome table
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        // 2) DP for minimum cuts
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for(int j = i; j < n; j++) {
                if(pal[i][j]) {
                    minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }
            dp[i] = minCuts;
        }

        return dp[0] - 1;
    }
};
