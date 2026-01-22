class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
         int limit = k*2;//each buy sell is 1 transection
        vector<int>front(limit+1,0), curr(limit+1,0);
        for(int i=n-1;i>=0;i--){
            for(int cap=0;cap<limit;cap++){//also reverse loop for cap possible
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