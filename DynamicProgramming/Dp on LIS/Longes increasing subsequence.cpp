class Solution {
public:
    int f(int i, int prev, int n,vector<int>& nums){
        if(i == n) return 0;
        //now 2 options notTake, take
        int notTake = 0+ f(i+1,prev,n,nums);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1+ f(i+1,i,n,nums);
        }
        return max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(0,-1,n, nums);//start from 0 and no prev idx so -1
    }
};

//Memoization
class Solution {
public:
    int f(int i, int prev, int n,vector<int>& nums, vector<vector<int>>&dp){
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        //now 2 options notTake, take
        int notTake = 0+ f(i+1,prev,n,nums,dp);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1+ f(i+1,i,n,nums,dp);
        }
        return dp[i][prev+1] =  max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n, nums,dp);//start from 0 and no prev idx is -1
    }
};

//
//Tabulation - this give run time error on large inputs due to large dp array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev =i-1; prev>=-1;prev--){
                int notTake = 0 + dp[i+1][prev+1];
                int take =0;
                if(prev == -1 || nums[i] > nums[prev]){
                    take = 1+ dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take, notTake);
            }
        }
        return dp[0][-1+1];
    }
};

//Space Optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
         vector<int>next(n+1,0), curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev =i-1; prev>=-1;prev--){
                int notTake = 0 + next[prev+1];
                int take =0;
                if(prev == -1 || nums[i] > nums[prev]){
                    take = 1+ next[i+1];
                }
               curr[prev+1] = max(take, notTake);
            }
            next = curr;
        }
        return next[-1+1];
    }
};
