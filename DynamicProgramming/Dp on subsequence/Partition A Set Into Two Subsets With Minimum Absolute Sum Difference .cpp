//recursive
class Solution {
  public:
  
  bool f(int idx, int tar, vector<int>& arr) {
      // base cases
      if (tar == 0) return true;
      if (idx == 0) return (arr[0] == tar);

      // not take
      bool notTake = f(idx - 1, tar, arr);

      // take
      bool take = false;
      if (arr[idx] <= tar) {
          take = f(idx - 1, tar - arr[idx], arr);
      }

      return take || notTake;
  }

  int minDifference(vector<int>& arr) {
      int n = arr.size();
      int totSum = 0;
      for (int x : arr) totSum += x;

      int half = totSum / 2;
      int mini = 1e9;

      for (int s1 = 0; s1 <= half; s1++) {
          if (f(n - 1, s1, arr)) {
              int s2 = totSum - s1;
              mini = min(mini, abs(s1 - s2));
          }
      }
      return mini;
  }
};



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
   
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n= arr.size();
         int totSum =0;
        for(int i=0;i<n;i++) totSum +=arr[i];
         int half = totSum / 2; 
        
      //dp[n-1][col-> 0,1,..totSum]
      vector<vector<int>>dp(n,vector<int>(half+1, -1));
        int mini = 1e9;
        for(int s1=0;s1<=half;s1++){
            if(f(n-1,s1,arr,dp) == true){
                int s2 = totSum-s1;////subset2 sum
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};

//tabulation
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n= arr.size();
         int totSum =0;
        for(int i=0;i<n;i++) totSum +=arr[i];
        int sum = totSum/2;
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
        
      //dp[n-1][col-> 0,1,..totSum]
        int mini = 1e9;
        for(int s1=0;s1<=totSum/2;s1++){
            if(dp[n-1][s1] == true){
                int s2 = totSum-s1;////subset2 sum
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};

//space optimisation with out tle
class Solution {

  public:
  
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n= arr.size();
         int totSum =0;
        for(int i=0;i<n;i++) totSum +=arr[i];
         int sum = totSum / 2; 
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
        
      //dp[n-1][col-> 0,1,..totSum]
        int mini = 1e9;
        for(int s1=0;s1<=totSum;s1++){
            if(prev[s1] == true){
                int s2 = totSum-s1;////subset2 sum
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};


//