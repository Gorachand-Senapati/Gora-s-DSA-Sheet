//recursion memoisation
class Solution {
  public:
     int f(int idx, vector<int>& nums, vector<int>& dp){
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;//it works when idx-2
    if(dp[idx] != -1) return dp[idx];
    //have 2 option rob current house or ignore it go 2nd house
    int pick = nums[idx] + f(idx-2,nums,dp);//if current then also go now without next house means no adjsent
    int notPick = 0 + f(idx-1, nums,dp);
    return dp[idx]= max(pick, notPick);
   }
    int maxValue(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1) return arr[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i !=0) temp1.push_back(arr[i]);
            if(i != n-1) temp2.push_back(arr[i]);
        }
        vector<int>dp1(temp1.size(),-1), dp2(temp2.size(),-1);
       int ans = max(f(temp1.size()-1,temp1,dp1) , f(temp2.size()-1,temp2,dp2));
       return ans;
    }
};
//tabulisation 
class Solution {
public:
   int find(vector<int>& nums) {
         int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take = nums[i]; if(i >1) take+=dp[i-2];//if pick then go 1 after
            int noTake = 0 + dp[i-1];
            dp[i]= max(take,noTake);
        }
        return dp[n-1];// best till entire array 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i !=0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        int ans = max(find(temp1), find(temp2));
        return ans;
    }
};

//space optimise
class Solution {
public:
   int find(vector<int>& arr) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i !=0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        int ans = max(find(temp1), find(temp2));
        return ans;
    }
};