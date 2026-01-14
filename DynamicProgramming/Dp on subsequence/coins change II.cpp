//memoization
class Solution {
public:
  int f(int idx, int target, vector<int>& coins,  vector<vector<int>>&dp){
    //base case
    if(idx ==0){
        if(target % coins[0] == 0) return 1;//when need total number of ways return 1 else 0 **
        else return 0;
    }
    if(dp[idx][target] != -1) return dp[idx][target];
    int notTake = f(idx-1,target,coins,dp);
    int take =0;
    if(coins[idx] <= target){
        take = f(idx,target-coins[idx], coins,dp);
    }
    return dp[idx][target] = take + notTake;
  }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return f(n-1,amount, coins,dp);

    }
};

//tabulation
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int t =0;t<=sum;t++){//base case**
            if(t % coins[0] == 0){
                dp[0][t] = 1;
            }else{
                dp[0][t] = 0;
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<= sum;t++){
                int notTake = dp[i-1][t];
                int take =0;
                if(t >= coins[i]){
                    take = dp[i][t - coins[i]];
                }
                dp[i][t] = take + notTake;
            }
        }
        return dp[n-1][sum];
    }
};

//space optimization
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int>prev(sum+1,0), curr(sum+1,0);
        for(int t =0;t<=sum;t++){//base case**
            if(t % coins[0] == 0){
                prev[t] = 1;
            }else{
                prev[t] = 0;
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<= sum;t++){
                int notTake = prev[t];
                int take =0;
                if(t >= coins[i]){
                    take = curr[t - coins[i]];
                }
                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};