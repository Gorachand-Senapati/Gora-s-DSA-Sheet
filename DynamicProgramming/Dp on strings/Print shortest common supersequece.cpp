class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] =0;//all col 0
        for(int j=0;j<=m;j++) dp[0][j] =0;//all row 0
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j]= 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //now reconstruct the string from dp table
        int i=n, j=m;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){//if match the char
              ans+= str1[i-1];//add in ans
              i--;j--;//go diagonal
            } else if(dp[i-1][j] > dp[i][j-1]){//go up
                ans+= str1[i-1];
                i--;
            } else {//go left
                ans+= str2[j-1];
                j--;
            }
            
        }
        //if have some char exists
            while(i > 0){//if (2,0)
                ans+= str1[i-1];
                i--;
            }
            while(j>0){//if (0,2)
                ans+= str2[j-1];
                j--;
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//TC: O(n*m + n + m)
//SC: O(n*m)