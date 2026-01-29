class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        //first copy first row and col value as it is
        for(int i=0;i<n;i++) dp[i][0] = matrix[i][0];//1st col
        for(int j=0;j<m;j++) dp[0][j] = matrix[0][j];//1st row 
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    dp[i][j]= matrix[i][j];
                }else{//min of left, diagonal, up
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1],dp[i-1][j])) +1;
                }
            }
        }
        int sum =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+= dp[i][j];
            }
        }
        return sum;
    }
};