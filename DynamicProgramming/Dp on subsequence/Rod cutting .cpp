//recursion
class Solution {
  public:
   int f(int idx, int len,vector<int> &price){
       if(idx ==0){
           //if len need 12 and here rod len =1 so need 12 times 1lenght
           return len * price[0];//n rods of length 1 need
       };
       int notTake = 0 + f(idx-1,len,price);
       int rodLen = idx+1;
       int take =-1e9;
       if(rodLen <= len){
           take = price[idx] + f(idx,len-rodLen,price);
       }
       return max(take,notTake);
   }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        return f(n-1,n, price);//n= length need of the rod
    }
};

//memoization
class Solution {
  public:
   int f(int idx, int len,vector<int> &price, vector<vector<int>>&dp){
       if(idx ==0){
           //if len need 12 and here rod len =1 so need 12 times 1lenght
           return len * price[0];//n rods of length 1 need
       };
       if(dp[idx][len]!= -1) return dp[idx][len];
       int notTake = 0 + f(idx-1,len,price,dp);
       int rodLen = idx+1;
       int take =-1e9;
       if(rodLen <= len){
           take = price[idx] + f(idx,len-rodLen,price,dp);
       }
       return dp[idx][len] = max(take,notTake);
   }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n, price,dp);//n= length need of the rod
    }
};
//tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        vector<vector<int>>dp(len,vector<int>(len+1,0));
        //base case from len 0 to N(need length )go the price[0]
        for(int n =0;n<=len;n++){
            dp[0][n]= price[0]*n;
        }
        for(int i=1;i<len;i++){//cover the price array
            for(int n=0;n<=len;n++){
                int notTake = 0 + dp[i-1][n];
                int rodLen = i+1;
                int take = -1e9;
                if(rodLen <= n){
                    take = price[i] + dp[i][n-rodLen];
                }
                dp[i][n] = max(take,notTake);
            }
        }
        return dp[len-1][len];
    }
};

//space optimization 2 arrays
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        vector<int>prev(len+1,0), curr(len+1,0);
        //base case from len 0 to N(need length )go the price[0]
        for(int n =0;n<=len;n++){
            prev[n]= price[0]*n;
        }
        for(int i=1;i<len;i++){//cover the price array
            for(int n=0;n<=len;n++){
                int notTake = 0 + prev[n];
                int rodLen = i+1;
                int take = -1e9;
                if(rodLen <= n){
                    take = price[i] +curr[n-rodLen];
                }
                curr[n] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[len];
    }
};
//space optimization 1 array
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        vector<int>prev(len+1,0);
        //base case from len 0 to N(need length )go the price[0]
        for(int n =0;n<=len;n++){
            prev[n]= price[0]*n;
        }
        for(int i=1;i<len;i++){//cover the price array
            for(int n=0;n<=len;n++){
                int notTake = 0 + prev[n];
                int rodLen = i+1;
                int take = -1e9;
                if(rodLen <= n){
                    take = price[i] +prev[n-rodLen];
                }
                prev[n] = max(take,notTake);
            }
        }
        return prev[len];
    }
};