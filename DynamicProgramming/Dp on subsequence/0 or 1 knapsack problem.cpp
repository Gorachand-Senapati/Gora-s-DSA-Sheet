class Solution {
  public:
    int f(int idx, int W,vector<int> &val, vector<int> &wt){
        //base case
        if(idx == 0){
            if(wt[0]<=W) return val[0];
            else return 0;//nothing pick
        }
        //possible all path
        int notTake = 0 + f(idx-1,W,val, wt);//W not change
        int take = 0;//min value //int min
        if(wt[idx] <=W){
            take = val[idx] + f(idx-1,W-wt[idx], val, wt);
        }
        return max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        return f(n-1,W, val, wt);
    }
};

//memoization
class Solution {
  public:
    int f(int idx, int W,vector<int> &val, vector<int> &wt, vector<vector<int>>&dp){
        //base case
        if(idx == 0){
            if(wt[0]<=W) return val[0];
            else return 0;//nothing pick
        }
        if(dp[idx][W] != -1) return dp[idx][W];
        //possible all path
        int notTake = 0 + f(idx-1,W,val, wt,dp);//W not change
        int take = 0;//min value
        if(wt[idx] <=W){
            take = val[idx] + f(idx-1,W-wt[idx], val, wt,dp);
        }
        return dp[idx][W] = max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,val, wt,dp);
    }
};

//tabulation
class Solution {
  public:
   
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int w =0;w<=W;w++){
            if(wt[0] <=w)dp[0][w]= val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<=W;j++){//j=weight
                 int notTake = 0 + dp[i-1][j];//W not change
                 int take = INT_MIN;//min value
                  if(wt[i] <=j){
                  take = val[i] +  dp[i-1][j-wt[i]];;
                  }
                  dp[i][j]= max(take,notTake);
            }
        }
        return dp[n-1][W];
    }
};

//space optimization
class Solution {
  public:
   
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int>prev(W+1,0), curr(W+1,0);
        for(int w =0;w<=W;w++){
            if(wt[0] <=w)prev[w]= val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<=W;j++){//j=weight
                 int notTake = 0 + prev[j];//W not change
                 int take = INT_MIN;//min value
                  if(wt[i] <=j){
                  take = val[i] +  prev[j-wt[i]];;
                  }
                  curr[j]= max(take,notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};

//space optimization with single array
class Solution {
  public:
   
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int>prev(W+1,0);
        for(int w =0;w<=W;w++){
            if(wt[0] <=w)prev[w]= val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =W;j>=0;j--){//j=weight now do right to left
                 int notTake = 0 + prev[j];//W not change
                 int take = INT_MIN;//min value
                  if(wt[i] <=j){
                  take = val[i] +  prev[j-wt[i]];;
                  }
                 prev[j]= max(take,notTake);
            }
           
        }
        return prev[W];
    }
};