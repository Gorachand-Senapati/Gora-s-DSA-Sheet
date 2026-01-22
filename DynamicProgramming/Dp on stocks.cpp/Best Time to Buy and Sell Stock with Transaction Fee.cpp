//memoization
class Solution {
public:
       int f(int idx,int buy, int n, vector<int>& prices, vector<vector<int>>&dp,int fee){
        //if last day not any profit make
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy == 1){ //if buy then 2 ops- take, not take
           profit = max(-prices[idx] + f(idx+1,0,n,prices,dp,fee), 
           0 + f(idx+1,1,n,prices,dp,fee));
        }else{// if sell sell that day or another day
           profit = max(prices[idx]-fee + f(idx+1,1,n,prices,dp,fee), 
           0 + f(idx+1,0,n,prices,dp,fee));
        }
        return dp[idx][buy]= profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));//buy 2 choice
        return  f(0,1,n,prices,dp,fee);//0 idx, 1->buy,0->not buy transection cnt =0
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));//buy 2 choice
        dp[n][0] = dp[n][1] = 0;//base case
        for(int idx = n-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
             int profit = 0;
             if(buy){ //if buy then 2 ops- take, not take
                profit = max(-prices[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
             }else{// if sell sell that day or another day
                profit = max(prices[idx]-fee + dp[idx+1][1], 0 + dp[idx+1][0]);
             }
              dp[idx][buy]= profit;
            }
        }
        return dp[0][1];//0 idx, 1->buy,0->not buy
    }
};