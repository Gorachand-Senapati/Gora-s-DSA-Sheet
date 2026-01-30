//recursion
class Solution {
  public:
    int f(int mask, int pos,vector<vector<int>>& cost){
        //base case if all visit menas 1111 all bit 1 then return 0 pos cost
        int n= cost.size();
        if(mask == (1<<n) -1){
            return cost[pos][0];
        }
        int ans = INT_MAX;
        //try visit all city which are not visit yet
        for(int i=0;i<n;i++){
            if((mask & (1<<i)) == 0){//means not visit
              ans = min(ans, cost[pos][i] + f(mask | (1<<i), i,cost));//set mask and again go which are not visited
            }
            
        }
        return ans;
    }
    int tsp(vector<vector<int>>& cost) {
        // code here
        int mask = 1,pos = 0;//mask say visit or not visit 1 means only 0 visit
        return f(mask,pos,cost);
    }
};

//memoization
class Solution {
  public:
    int f(int mask, int pos,vector<vector<int>>& cost,vector<vector<int>>&dp){
        //base case if all visit menas 1111 all bit 1 then return 0 pos cost
        int n= cost.size();
        if(mask == (1<<n) -1){
            return cost[pos][0];
        }
        if( dp[pos][mask] != -1) return  dp[pos][mask];
        int ans = INT_MAX;
        //try visit all city which are not visit yet
        for(int i=0;i<n;i++){
            if((mask & (1<<i)) == 0){//means not visit
              ans = min(ans, cost[pos][i] + f(mask | (1<<i), i,cost,dp));//set mask and again go which are not visited
            }
            
        }
        return dp[pos][mask] =  ans;
    }
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n = cost.size();
        int mask = 1,pos = 0;//mask say visit or not visit 1 means only 0 visit
        vector<vector<int>>dp(n, vector<int>(1<<n,-1));
        return f(mask,pos,cost,dp);
    }
};

//tabulation
class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int mask = 1,pos = 0;//mask say visit or not visit 1 means only 0 visit
        vector<vector<int>>dp(n, vector<int>(1<<n,INT_MAX));
        //base case
        for(int i=0;i<n;i++){
            if(i==0) dp[i][(1<<n)-1] = cost[i][0];//if all visited and at 0th pos
            else dp[i][(1<<n)-1] = cost[i][0];//if all visited and at ith pos
        }
        
        //traversing all mask from (1<<n)-1 to 0
        for(int mask = (1<<n)-1;mask>=0;mask--){
            for(int pos=0;pos<n;pos++){
                //try visit all city which are not visit yet
                for(int i=0;i<n;i++){
                    if((mask & (1<<i)) == 0){//means not visit
                      dp[pos][mask] = min(dp[pos][mask], cost[pos][i] + dp[i][mask | (1<<i)]);//set mask and again go which are not visited
                    }

                }
            }
        }
        return dp[0][1];//starting from 0th pos and only 0th visited
    }
}; //TC: O(n * 2^n * n) SC: O(n * 2^n)