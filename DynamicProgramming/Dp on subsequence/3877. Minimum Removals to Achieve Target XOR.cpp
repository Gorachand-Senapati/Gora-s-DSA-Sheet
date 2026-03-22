//recursion
class Solution {
public:
   int f(int i, int target, vector<int>& nums){
    if(i < 0){
        if(target ==0) return 0;
        else return 1e9;//max value
    }
    int notTake = 1 + f(i-1,target,nums);
    int take = 0 + f(i-1,target ^ nums[i], nums);
    return min(take,notTake);
   }
    int minRemovals(vector<int>& nums, int target) {
        int n =nums.size();
        int ans = f(n-1,target,nums);
        return (ans >= 1e9) ? -1 : ans;
    }
};

//memoization
//class Solution {
public:
   int f(int i, int target, vector<int>& nums, vector<vector<int>>&dp){
    if(i < 0){
        if(target ==0) return 0;
        else return 1e9;//max value
    }
    if(dp[i][target] != -1) return dp[i][target];
    int notTake = 1 + f(i-1,target,nums,dp);
    int take = 0 + f(i-1,target ^ nums[i], nums,dp);
    return dp[i][target]= min(take,notTake);
   }
    int minRemovals(vector<int>& nums, int target) {
        int n =nums.size();
        vector<vector<int>>dp(n,vector<int>(16384,-1));
        int ans = f(n-1,target,nums,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};

//tabulation
class Solution {
public:    int minRemovals(vector<int>& nums, int target) {
        int n =nums.size();
        vector<vector<int>>dp(n+1,vector<int>(16384,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<16384;j++){
                if(i == 0){
                    dp[i][j] = (j == 0) ? 0 : 1e9;
                }else{
                    int notTake = 1 + dp[i-1][j];
                    int take = 0 + dp[i-1][j ^ nums[i-1]];
                    dp[i][j] = min(take,notTake);
                }
            }
        }
        int ans = dp[n][target];
        return (ans >= 1e9) ? -1 : ans;
    }
};