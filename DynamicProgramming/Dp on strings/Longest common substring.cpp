//tabulation 
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
         int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //base case when shifting
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        //parmeter change
        int ans =0;
        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]== s2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j]= 0;//need else reset if not match
            }
        }
        return ans;
    }
};

//space optimized
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
         int n = s1.size(), m = s2.size();
        vector<int>prev(m+1,0), curr(m+1,0);
        //base case when shifting
        for(int j=0;j<=m;j++)prev[j]=0;//need only 1st row
        //parmeter change
        int ans =0;
        for(int i=1;i<=n; i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]== s2[j-1]){
                   curr[j]= 1 + prev[j-1];
                    ans = max(ans, curr[j]);
                }
                else curr[j]= 0;//need else reset if not match
            }
            prev = curr;
        }
        return ans;
    }
};