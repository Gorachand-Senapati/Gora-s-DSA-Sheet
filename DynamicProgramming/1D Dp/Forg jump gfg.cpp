// Find minimum number of jumps to reach end of an array

//normal recursion
class Solution {
private:
 int f(int idx, vector<int>& height ){
     if(idx == 0) return 0;
     int left = f(idx -1, height)+ abs(height[idx] - height[idx-1]); 
     int right = INT_MAX;//bcz right start from 1
     if(idx >1) right = f(idx -2, height)+ abs(height[idx] - height[idx-2]);
     return min(left,right);
 }

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        return f(n-1, height);
        
    }
};
//memoization //top down`
class Solution {
    // memoization
private:
 int f(int idx, vector<int>& height,vector<int>&dp ){
     //step 1 give parameter of all function
     if(idx == 0) return 0;
     if(dp[idx]!= -1) return dp[idx]; //step[3]check
     int left = f(idx -1, height,dp)+ abs(height[idx] - height[idx-1]); 
     int right = INT_MAX;//bcz right start from 1
     if(idx >1) right = f(idx -2, height,dp)+ abs(height[idx] - height[idx-2]);
     return dp[idx]= min(left,right);//step 2 put the value
 }

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n,-1);
        return f(n-1, height,dp);
        
    }
};

//tabulation //bottom up
class Solution {

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            int fs= dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){//if start from 2 -2 not allow from 1
                 ss= dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i]= min(fs,ss);
        }
        return dp[n-1];
    }
};

//space optimized
class Solution {

  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev=0, prev2=0;
        for(int i=1;i<n;i++){
            int fs= prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){//if start from 2 -2 not allow from 1
                 ss= prev2 + abs(height[i] - height[i-2]);
            }
            int curr_pos= min(fs,ss);
            prev2= prev;prev= curr_pos;
        }
        return prev;
    }
};

//now if we have k jumps means form i-1,i-2...i-k
// normal recursion
class Solution  {
private:
 int f(int idx, vector<int>& height ,int k){
     if(idx == 0) return 0;
     int minSteps = INT_MAX;
     for(int j=1;j<=k;j++){
         if(idx - j >=0){
             int jump = f(idx -j, height,k)+ abs(height[idx] - height[idx-j]);
             minSteps = min(minSteps,jump);
         }
     }
     return minSteps;
 }

  public:
    int minCost(vector<int>& height, int k) {
        int n = height.size();
        return f(n-1, height,k);
        
    }
} //TC: O(k^n) SC: O(n) for recursion stack

;//memoization
class Solution  {
private:    
 int f(int idx, vector<int>& height ,int k,vector<int>&dp){
     if(idx == 0) return 0;
     if(dp[idx]!= -1) return dp[idx];
     int minSteps = INT_MAX;
     for(int j=1;j<=k;j++){
         if(idx - j >=0){
             int jump = f(idx -j, height,k,dp)+ abs(height[idx] - height[idx-j]);
             minSteps = min(minSteps,jump);
         }
     }
     return dp[idx]= minSteps;
 }

  public:
    int minCost(vector<int>& height, int k) {
        int n = height.size();
        vector<int>dp(n+1,-1);
        return f(n-1, height,k,dp);
        
    }
};//TC: O(n*k) SC: O(n) for recursion stack + O(n) for dp array 

//tabulation //bottom up
class Solution  {

  public:
    int minCost(vector<int>& height, int k) {
        int n = height.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            int minSteps = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i - j >=0){
                    int jump = dp[i -j]+ abs(height[i] - height[i-j]);
                    minSteps = min(minSteps,jump);
                }
            }
            dp[i]= minSteps;
        }
        return dp[n-1];
    }
};//TC: O(n*k) SC: O(n) for dp array

//space optimized not possible bcz we have to check k previous states so if k=n then we have to store all previous states then the list store . so same O(n) SC
// but approach is use a list and from i-1 to i-k store in the array and when 2nd traverse simple increase it +1 
