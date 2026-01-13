class Solution {//recursion
public:
    int f(int idx, int target, vector<int>& coins){
        //base case
        if(idx == 0){
            if(target % coins[0] == 0) return target / coins[0];
            else return 1e9;//intmax
        }
        int notTake = 0 + f(idx-1,target,coins);
        int take = 1e9;
        if(coins[idx]<= target){
            take = 1 + f(idx,target-coins[idx],coins);
        }
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        int ans = f(n-1,amount, coins);
        if(ans >=1e9) return -1;
        return ans;
    }
};

//memoization
class Solution {
public:
    int f(int idx, int target, vector<int>& coins, vector<vector<int>>&dp){
        //base case
        if(idx == 0){
            if(target % coins[0] == 0) return target / coins[0];
            else return 1e9;//intmax
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = 0 + f(idx-1,target,coins,dp);
        int take = 1e9;
        if(coins[idx]<= target){
            take = 1 + f(idx,target-coins[idx],coins,dp);
        }
        return dp[idx][target] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount, coins,dp);
        if(ans >=1e9) return -1;
        return ans;
    }
};

//tabulation
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //base case
        for(int t=0;t<=amount;t++){
            if(t % coins[0] == 0){
                dp[0][t] = t/coins[0];
            }else{
                 dp[0][t] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notTake = 0 + dp[i-1][t];
                int take =1e9;
                if(coins[i] <= t){
                    take = 1 + dp[i][t-coins[i]];
                }
                dp[i][t] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >=1e9) return -1;
        return ans;
    }
};

//space optimization
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);
        //base case
        for(int t=0;t<=amount;t++){
            if(t % coins[0] == 0){
                prev[t] = t/coins[0];
            }else{
                 prev[t] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int notTake = 0 + prev[t];
                int take =1e9;
                if(coins[i] <= t){
                    take = 1 + curr[t-coins[i]];
                }
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >=1e9) return -1;
        return ans;
    }
};