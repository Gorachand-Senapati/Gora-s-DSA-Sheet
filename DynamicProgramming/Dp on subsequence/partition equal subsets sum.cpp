//memoization
class Solution {
public:
  bool f(int idx, int tar,vector<int>& arr,  vector<vector<int>>&dp){
       //base case
       if(tar ==0) return true;
       if(idx ==0) return (arr[0] == tar);//if 1st index is tar then true
       //all path take, not take
       if(dp[idx][tar] != -1) return dp[idx][tar];
       bool notTake = f(idx-1,tar, arr,dp);
       bool take = false;//initialise
       if(arr[idx] <= tar){
           take= f(idx-1, tar-arr[idx], arr,dp);
       }
       return dp[idx][tar] = notTake || take;//t= 1, f=0
   }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totSum = 0;
        for(int i=0;i<nums.size();i++) totSum+= nums[i];
        if(totSum %2 != 0) return false;//odd num never devide 2 parts
        int target = totSum/2;
         vector<vector<int>>dp(n, vector<int>(target+1,-1));
         return f(n-1, target,nums,dp);
    }
};

//tabulation
class Solution {
public:
  bool isSubsetSum(vector<int>& arr, int sum) {//sum = target
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1,false));
        //base case
        for(int i=0;i<n;i++){//means any time target 0
            dp[i][0] = true;// If the target sum is 0, we can always achieve it by taking no elements
        }
        if(arr[0] <= sum){//take it
            dp[0][arr[0]]= true;// If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
        }
        for(int i =1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                //if not take
                bool notTake = dp[i-1][tar];
                bool take = false;
                if(arr[i] <= tar){
                    take = dp[i-1][tar-arr[i]];
                }
                dp[i][tar]= take || notTake;
            }
        }
        return dp[n-1][sum];
    };

    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totSum = 0;
        for(int i=0;i<nums.size();i++) totSum+= nums[i];
        if(totSum %2 != 0) return false;//odd num never devide 2 parts
        int target = totSum/2;
         return isSubsetSum(nums, target);
    }
};
//space optimisation
class Solution {
public:
 bool isSubsetSum(vector<int>& arr, int sum) {//sum = target
        // code here
        int n = arr.size();
        vector<bool>prev(sum+1,false), curr(sum+1,false);
      //base case  //if sum 0 not need to pick any thing
        prev[0]=curr[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;//if have one element and if bigger than target then false
        for(int i =1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                //if not take
                bool notTake = prev[tar];
                bool take = false;
                if(arr[i] <= tar){
                    take = prev[tar-arr[i]];
                }
                curr[tar]= take || notTake;
            }
            prev = curr;
        }
        return prev [sum];
    };

    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totSum = 0;
        for(int i=0;i<nums.size();i++) totSum+= nums[i];
        if(totSum %2 != 0) return false;//odd num never devide 2 parts
        int target = totSum/2;
         return isSubsetSum(nums, target);
    }
};