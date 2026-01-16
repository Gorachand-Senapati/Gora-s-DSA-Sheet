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
    int minInsertions(string s) {
        int n = s.size();
        string t =s;
        reverse(t.begin(), t.end());
        int pLen = lcs(s,t);//already palindrom in the string
        return n-pLen;
    }
};