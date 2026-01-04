//using recursion
class Solution {
public:
   int f(int idx, vector<int>& nums){
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;//it works when idx-2
    //have 2 option rob current house or ignore it go 2nd house
    int pick = nums[idx] + f(idx-2,nums);//if current then also go now without next house means no adjsent
    int notPick = 0 + f(idx-1, nums);
    return max(pick, notPick);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(n-1, nums);
    }
};

//Memoisation
class Solution {
public:
   int f(int idx, vector<int>& nums, vector<int>&dp){
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;//it works when idx-2
    if(dp[idx] != -1) return dp[idx];//its not put after 1st if so then give runtime error
    //have 2 option rob current house or ignore it go 2nd house
    int pick = nums[idx] + f(idx-2,nums,dp);//if current then also go now without next house means no adjsent
    int notPick = 0 + f(idx-1, nums,dp);
    return dp[idx]= max(pick, notPick);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1, nums,dp);
    }
};

//tabulisation
class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        int neg = 0;
        for(int i=1;i<n;i++){
            int take = nums[i]; if(i >1) take+=dp[i-2];//if pick then go 1 after
            int noTake = 0 + dp[i-1];
            dp[i]= max(take,noTake);
        }
        return dp[n-1];// best till entire array ✅
    }
};

//space optimisation
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int prev =arr[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = arr[i]; if(i >1) take+=prev2;//if pick then go 1 after
            int noTake = 0 + prev;
             int curr_i= max(take,noTake);
            prev2 = prev;
            prev= curr_i;
        }
        return prev;
    }
};
