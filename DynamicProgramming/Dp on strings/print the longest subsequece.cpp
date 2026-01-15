#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 using namespace std;

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
        //reconstruct the lcs string from dp table
        int i= n, j=m;//last cell
        string LCS = "";
        //traverse dp table from bottom right to top left
        while(i >0 && j>0){
            if(s1[i-1] == s2[j-1]){//if match the char
                LCS+= s1[i-1];//store the char
                //go diagonally
                i--; j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                //move to the greater value 
                i--;
            }else{//otherwise opposite greater value
                j--;
            }
        }
        reverse(LCS.begin(), LCS.end());//reverse the string
         cout << "LCS = " << LCS << endl;
    }
};

int main() {
    Solution obj;
    string s1 = "bcdek", s2 = "abedk";
     obj.lcs(s1,s2);
    return 0;
}