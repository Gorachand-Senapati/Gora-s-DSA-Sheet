//recursion
class Solution {
  public:
    int f(int idx, int capacity,vector<int>& val, vector<int>& wt){
        //base case
        if(idx ==0){
            return (capacity /wt[0])* val[0];
        }
        int notTake = 0 + f(idx-1,capacity,val,wt);
        int take = 0;
        if(wt[idx] <= capacity){
            take = val[idx]+ f(idx,capacity-wt[idx],val,wt);
        }
        return max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        int ans = f(n-1,capacity,val,wt);
        return ans;
    }
};

//memoization
class Solution {
  public:
    int f(int idx, int capacity,vector<int>& val, vector<int>& wt,vector<vector<int>>&dp){
        //base case
        if(idx ==0){
            return (capacity /wt[0])* val[0];//this is the improtant in this duplicate
        }
        if(dp[idx][capacity] != -1) return dp[idx][capacity];
        int notTake = 0 + f(idx-1,capacity,val,wt,dp);
        int take = 0;
        if(wt[idx] <= capacity){
            take = val[idx]+ f(idx,capacity-wt[idx],val,wt,dp);
        }
        return dp[idx][capacity] =  max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1,-1));
        int ans = f(n-1,capacity,val,wt,dp);
        return ans;
    }
};

//tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1,0));
        for(int w =0;w<=capacity;w++){
            if(wt[0] <=w)dp[0][w]= (w/wt[0])* val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<=capacity;j++){//j=weight
                 int notTake = 0 + dp[i-1][j];//W not change
                 int take = 0;//min value
                  if(wt[i] <=j){
                  take = val[i] +  dp[i][j-wt[i]];;
                  }
                  dp[i][j]= max(take,notTake);
            }
        }
        return dp[n-1][capacity];
    }
};
//space optimization //2 arrays
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
         vector<int>prev(capacity+1,0), curr(capacity+1,0);
        for(int w =0;w<=capacity;w++){
            if(wt[0] <=w)prev[w]= (w/wt[0])* val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<= capacity;j++){//j=weight
                 int notTake = 0 + prev[j];//W not change
                 int take = 0;//min value
                  if(wt[i] <=j){
                  take = val[i] +  curr[j-wt[i]];;
                  }
                  curr[j]= max(take,notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};

//space optimization //1 array
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
         vector<int>prev(capacity+1,0);
        for(int w =0;w<=capacity;w++){
            if(wt[0] <=w)prev[w]= (w/wt[0])* val[0];//if 1st ind wt is small than maxWt
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<= capacity;j++){//j=weight
                 int notTake = 0 + prev[j];//W not change
                 int take = 0;//min value
                  if(wt[i] <=j){
                  take = val[i] +  prev[j-wt[i]];;
                  }
                  prev[j]= max(take,notTake);
            }
           
        }
        return prev[capacity];
    }
};