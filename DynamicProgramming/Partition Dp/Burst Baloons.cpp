//recursion
class Solution {
public:
   int f(int i, int j,vector<int>& nums){
      //base case
      if(i > j) return 0;
      int maxi = INT_MIN;
     for(int idx =i;idx<=j;idx++){
         int cost = nums[i-1] * nums[idx] * nums[j+1] + 
                     f(i,idx-1,nums) + f(idx+1,j,nums);//subproblem left, right
         maxi = max(maxi, cost);
     }
     return maxi;
   }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);//add back 1
        nums.insert(nums.begin(),1);//add front 1
        return f(1,n,nums);
    }
};

//memoization
class Solution {
public:
   int f(int i, int j,vector<int>& nums, vector<vector<int>>&dp){
      //base case
      if(i > j) return 0;
      if(dp[i][j] != -1) return dp[i][j];
      int maxi = INT_MIN;
     for(int idx =i;idx<=j;idx++){
         int cost = nums[i-1] * nums[idx] * nums[j+1] + 
                     f(i,idx-1,nums,dp) + f(idx+1,j,nums,dp);//subproblem left, right
         maxi = max(maxi, cost);
     }
     return dp[i][j] = maxi;
   }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);//add back 1
        nums.insert(nums.begin(),1);//add front 1
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};

//tabulation
class Solution {
  public:
    int maxSkill(vector<int> &arr) {
        int n = arr.size();
        arr.push_back(1);//add back 1
        arr.insert(arr.begin(),1);//add front 1
        vector<vector<int>>dp(n+2, vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){//j always right of the i so not need to write form 1
                if(i > j) continue;
                int maxi = INT_MIN;
                for(int idx = i;idx<=j;idx++){
                    int cost = arr[i-1] * arr[idx] * arr[j+1] + 
                     dp[i][idx-1] + dp[idx+1][j];//subproblem left, right
                      maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};