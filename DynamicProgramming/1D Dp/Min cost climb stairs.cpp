//recursion
class Solution {
public: 
    int f(int i, vector<int>& cost){
        if(i == 0 || i == 1) return cost[i];
        int fs = cost[i] + f(i-1,cost);
        int ss =INT_MAX;
        if(i >1) ss = cost[i] + f(i-2,cost);
        return min(fs,ss);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(f(n-1, cost), f(n-2, cost));//because top n-1 & n-2 also 
    }
};

//memoisation
class Solution {
public: 
    int f(int i, vector<int>& cost,vector<int>&dp){
        if(i == 0 || i == 1) return cost[i];
        if(dp[i] != -1) return dp[i];
        int fs = cost[i] + f(i-1,cost,dp);
        int ss =INT_MAX;
        if(i >1) ss = cost[i] + f(i-2,cost,dp);
        return dp[i]= min(fs,ss);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(f(n-1, cost,dp), f(n-2, cost,dp));//because top n-1 & n-2 also 
    }
};

//tabulisation
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int>dp(n,0);
        dp[0]=cost[0],dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int fs = cost[i] + dp[i-1];
            int ss = cost[i] + dp[i-2];
            dp[i] = min(fs,ss);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

//space optimisation
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        int prev2=cost[0],prev1=cost[1];
        for(int i=2;i<n;i++){
            int fs = cost[i] + prev1;
            int ss = cost[i] + prev2;
            int curr = min(fs,ss);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1, prev2);
    }
};