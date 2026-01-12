//method 1: recursion + memoization
class Solution {
  public:
  //if given large ip then do mod = 1e9 +7
  int f(int idx, int tar,vector<int>& arr, vector<vector<int>>&dp){
      //base case
      if (idx == 0) {
        if (tar == 0 && arr[0] == 0) return 2; // take or not take
        if (tar == 0 || arr[0] == tar) return 1;//when tar came
         return 0;
      }// after get tar =0 not finish this step go till 1st index
      if(dp[idx][tar] != -1) return dp[idx][tar];
      int notTake = f(idx-1,tar,arr,dp);
      int take =0;//false
      if(arr[idx] <= tar){
          take = f(idx-1,tar-arr[idx], arr,dp);
      }
      return dp[idx][tar] = notTake + take;//  %mod
  }
    int countPartitions(vector<int>& arr, int diff) {
       int n = arr.size(), totSum =0;
       for(int x: arr) totSum+=x;
       
       if(totSum-diff <0 || (totSum -diff)% 2 != 0) return 0;//need 2 or more no odd
        int target = (totSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1, target, arr,dp);
    }
};

//tabulation
class Solution {
  public:
  //if given large ip then do mod = 1e9 +7
 int findWay(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        //any time tar =0 base case rturn 1
        if(arr[0] == 0){
            dp[0][0] =2;//tar =0 and arr[0] take or nottake
        } else{
            dp[0][0] =1;//came to last index arr[0] !=0
        }
        if(arr[0]!=0 && arr[0] <= target){
            dp[0][arr[0]]=1;//means if need 5 and arr0 =5 so 1 way 
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){//all target need to be covered star from 0 to target bcause we have to fill all dp
                int notTake = dp[i-1][tar];
                int take =0;
                if(arr[i]<=tar){
                    take = dp[i-1][tar-arr[i]];
                }
                dp[i][tar] = (notTake + take) ;
            }
        }
        return dp[n-1][target];
    }
    int countPartitions(vector<int>& arr, int diff) {
       int n = arr.size(), totSum =0;
       for(int x: arr) totSum+=x;
       if(totSum-diff <0 || (totSum -diff)% 2 != 0) return 0;//need 2 or more no odd
        int target = (totSum-diff)/2;
        return findWay(arr,target);
    }
};

//space optimization
class Solution {
  public:
  //if given large ip then do mod = 1e9 +7
  int findWay(vector<int>& arr, int target) {
        // code here
        
        int n = arr.size();
        vector<int>prev(target+1,0), curr(target+1,0);
        //any time tar =0 base case rturn 1
        if(arr[0] == 0){
            prev[0] =2;//tar =0 and take or nottake
        } else{
            prev[0] =1;//came to last index 
        }
        if(arr[0]!=0 && arr[0] <= target){
            prev[arr[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){//all target need to be covered star from 0 to target bcause we have to fill all dp
                int notTake = prev[tar];
                int take =0;
                if(arr[i]<=tar){
                    take = prev[tar-arr[i]];
                }
                curr[tar] = (notTake + take);
            }
            prev = curr;
        }
        return prev[target];
    }
    int countPartitions(vector<int>& arr, int diff) {
       int n = arr.size(), totSum =0;
       for(int x: arr) totSum+=x;
       if(totSum-diff <0 || (totSum -diff)% 2 != 0) return 0;//need 2 or more no odd
        int target = (totSum-diff)/2;
        return findWay(arr,target);
    }
};