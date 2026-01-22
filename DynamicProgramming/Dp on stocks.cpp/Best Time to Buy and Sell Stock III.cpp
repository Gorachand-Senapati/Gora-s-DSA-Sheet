//recursion
class Solution {
public:
    int f(int idx,int buy, int n, vector<int>& prices,int cap){
        //if last day not any profit make
        if(cap == 0) return 0;
        if(idx == n) return 0;
        int profit = 0;
        if(buy){ //if buy then 2 ops- take, not take
           profit = max(-prices[idx] + f(idx+1,0,n,prices,cap), 0 + f(idx+1,1,n,prices,cap));
        }else{// if sell sell that day or another day
           profit = max(prices[idx] + f(idx+1,1,n,prices,cap-1), 0 + f(idx+1,0,n,prices,cap));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0,1,n,prices,2);//0 idx, 1->buy,0->not buy
    }
};


//memoization
class Solution {
public:
    int f(int idx,int buy, int n, vector<int>& prices, vector<vector<vector<int>>>&dp, int cap){
        //if last day not any profit make
        if(cap ==0) return 0;
        if(idx == n) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){ //if buy then 2 ops- take, not take
           profit = max(-prices[idx] + f(idx+1,0,n,prices,dp,cap), 0 + f(idx+1,1,n,prices,dp,cap));
        }else{// if sell sell that day or another day
           profit = max(prices[idx] + f(idx+1,1,n,prices,dp,cap-1), 0 + f(idx+1,0,n,prices,dp,cap));
        }
        return dp[idx][buy][cap]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,n,prices,dp,2);//0 idx, 1->buy,0->not buy
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //already 0 so no need to write base case if something else then need to write
        for(int idx =n-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
                for(int cap =1;cap<=2;cap++){//already 0 cover
                 int profit = 0;
                 if(buy){ //if buy then 2 ops- take, not take
                    profit = max(-prices[idx] +dp[idx+1][0][cap], 0 + dp[idx+1][1][cap]);
                 }else{// if sell sell that day or another day
                    profit = max(prices[idx] + dp[idx+1][1][cap-1], 0 + dp[idx+1][0][cap]);
                 }
                 dp[idx][buy][cap]= profit; 
                }
            }
        }

        return dp[0][1][2];//0 idx, 1->buy,0->not buy max 2 transection allow
    }
};

//space optimization O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>after(2,vector<int>(3,0));
       vector<vector<int>>curr(2,vector<int>(3,0));
        //already 0 so no need to write base case if something else then need to write
        for(int idx =n-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
                for(int cap =1;cap<=2;cap++){//already 0 cover
                 int profit = 0;
                 if(buy){ //if buy then 2 ops- take, not take
                    profit = max(-prices[idx] + after[0][cap], 0 + after[1][cap]);
                 }else{// if sell sell that day or another day
                    profit = max(prices[idx] + after[1][cap-1], 0 + after[0][cap]);
                 }
                curr[buy][cap]= profit; 
                }
            }
            after = curr;
        }

        return after[1][2];//0 idx, 1->buy,0->not buy max 2 transection allow
    }
};


//another approach memoization with 4 states n*4 dp need
class Solution {
  public:
    int f(int i, int cap,int n,vector<int> &prices,vector<vector<int>>&dp){
        //base case
        if(i ==n || cap ==4)return 0;//cap max limit 4
        if(dp[i][cap] != -1) return dp[i][cap];
        int profit = 0;
        if(cap %2 ==0){//buy
            profit = max(-prices[i] + f(i+1,cap+1,n,prices,dp), 
            0+f(i+1,cap,n,prices,dp));
        }else{//sell
            profit= max(prices[i] + f(i+1,cap+1,n,prices,dp),
            0+ f(i+1,cap,n,prices,dp));
        }
        return dp[i][cap] = profit;
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,n,prices,dp);//start 0 day and 0 transection
    }


    //tabulation
    class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int i=n-1;i>=0;i--){
            for(int cap=0;cap<4;cap++){
                int profit = 0;
                if(cap %2 ==0){//buy
                    profit = max(-prices[i] + dp[i+1][cap+1],0+dp[i+1][cap]);
                }else{//sell
                    profit= max(prices[i] + dp[i+1][cap+1], 0+ dp[i+1][cap]);
                }
                  dp[i][cap] = profit;
            }
        }
        return dp[0][0];//start 0 day and 0 transection
    }
};

//space optimization
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<int>front(5,0), curr(5,0);
        for(int i=n-1;i>=0;i--){
            for(int cap=0;cap<4;cap++){
                int profit = 0;
                if(cap %2 ==0){//buy
                    profit = max(-prices[i] + front[cap+1],0+front[cap]);
                }else{//sell
                    profit= max(prices[i] + front[cap+1], 0+ front[cap]);
                }
                  curr[cap] = profit;
            }
            front = curr;
        }
        return front[0];//start 0 day and 0 transection
    }
};