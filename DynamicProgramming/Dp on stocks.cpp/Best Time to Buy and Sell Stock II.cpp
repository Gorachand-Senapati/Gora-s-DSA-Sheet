//recursion
class Solution {
public:
    int f(int idx,int buy, int n, vector<int>& prices){
        //if last day not any profit make
        if(idx == n) return 0;
        int profit = 0;
        if(buy==1){ //if buy then 2 ops- take, not take
           profit = max(-prices[idx] + f(idx+1,0,n,prices), 0 + f(idx+1,1,n,prices));
        }else{// if sell sell that day or another day
           profit = max(prices[idx] + f(idx+1,1,n,prices), 0 + f(idx+1,0,n,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0,1,n,prices);//0 idx, 1->buy,0->not buy
    }
};

//memoization
class Solution {
public:
    int f(int idx,int buy, int n, vector<int>& prices, vector<vector<int>>&dp){
        //if last day not any profit make
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy == 1){ //if buy then 2 ops- take, not take
           profit = max(-prices[idx] + f(idx+1,0,n,prices,dp), 0 + f(idx+1,1,n,prices,dp));
        }else{// if sell sell that day or another day
           profit = max(prices[idx] + f(idx+1,1,n,prices,dp), 0 + f(idx+1,0,n,prices,dp));
        }
        return dp[idx][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));//buy 2 choice
        return f(0,1,n,prices,dp);//0 idx, 1->buy,0->not buy
    }
};
//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));//buy 2 choice
        dp[n][0] = dp[n][1] = 0;//base case
        for(int idx = n-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
             int profit = 0;
             if(buy){ //if buy then 2 ops- take, not take
                profit = max(-prices[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
             }else{// if sell sell that day or another day
                profit = max(prices[idx] + dp[idx+1][1], 0 + dp[idx+1][0]);
             }
              dp[idx][buy]= profit;
            }
        }
        return dp[0][1];//0 idx, 1->buy,0->not buy
    }
};

//space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<int>front(2,0), curr(2,0);//buy 2 choice
        front[0] =front[1] = 0;//base case
        for(int idx = n-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
             int profit = 0;
             if(buy){ //if buy then 2 ops- take, not take
                profit = max(-prices[idx] + front[0], 0 + front[1]);
             }else{// if sell sell that day or another day
                profit = max(prices[idx] + front[1], 0 + front[0]);
             }
              curr[buy]= profit;
            }
            front = curr;
        }
        return front[1];//0 idx, 1->buy,0->not buy
    }
};

//using simple one pass 4 variables
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       int frontBuy, frontNotBuy,currBuy, currNotBuy;
        frontNotBuy =frontBuy= 0;//base case
        for(int idx = n-1;idx>=0;idx--){
                currBuy = max(-prices[idx] +frontNotBuy, 0 + frontBuy);
                currNotBuy = max(prices[idx] + frontBuy, 0 + frontNotBuy);
            frontNotBuy = currNotBuy;
            frontBuy = currBuy;
        }
        return frontBuy;//0 idx, 1->buy,0->not buy
    }
};