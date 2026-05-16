//memoization 
class Solution {
  public:
    int f(int i, int prev, int n,vector<int>& arr,vector<vector<int>>&dp ){
        if(i==n) return 0;
        if(dp[i][prev+1] != -1)return dp[i][prev+1];
         int notTake = 0+ f(i+1,prev,n,arr,dp);
         
         int take = 0;
         if(prev == -1 || arr[prev] < arr[i]){
             take = arr[i]+ f(i+1,i,n,arr,dp);
         }
         return dp[i][prev+1] = max(take, notTake);
    }
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return f(0,-1,n,arr,dp);
    }
};
//tabulation

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int prev = i-1;prev>=-1;prev--){
                int notTake = 0+ dp[i+1][prev+1];
         
                int take = 0;
                if(prev == -1 || arr[prev] < arr[i]){
                    take = arr[i]+ dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};


//space optimization




//O(n)
int maxSumIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp = arr;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}