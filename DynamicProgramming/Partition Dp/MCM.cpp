//recursion
class Solution {
  public:
    int f(int i, int j, vector<int> &arr){
        //base case
        if(i == j) return 0;//if single element no operation
        int mini = 1e9;
        for(int k=i;k<j;k++){
            int cost1 = f(i,k,arr);
            int cost2 = f(k+1,j,arr);
            int costMultiply = arr[i-1] * arr[k] * arr[j] ;
            //total cost for this partition
            int total = cost1 + cost2 + costMultiply;
            mini= min(mini,total);
        }
        return mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        return f(1,n-1,arr);//start from 1 to n-1
    }
};
//memoization

class Solution {
  public:
    int f(int i, int j, vector<int> &arr,vector<vector<int>>&dp){
        //base case
        if(i == j) return 0;//if single element no operation
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i;k<j;k++){
            int cost1 = f(i,k,arr,dp);
            int cost2 = f(k+1,j,arr,dp);
            int costMultiply = arr[i-1] * arr[k] * arr[j] ;
            //total cost for this partition
            int total = cost1 + cost2 + costMultiply;
            mini= min(mini,total);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(1,n-1,arr,dp);//start from 1 to n-1
    }
};

//tabulation
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        //base case- a single matrix not need multiplication
        for(int i=1;i<n;i++) dp[i][i] = 0;//already 0 cover when assign
        for(int i= n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){//need j to left of i
                int mini = 1e9;
                for(int k=i;k<j;k++){
                    int cost1 = dp[i][k];
                    int cost2 = dp[k+1][j];
                    int costMultiply = arr[i-1]* arr[k]* arr[j];
                    int total = cost1 + cost2 + costMultiply;
                    mini = min(mini, total);
                }
                dp[i][j]= mini;
            }
        }
        return dp[1][n-1];//start from 1 to n-1
    }
};
