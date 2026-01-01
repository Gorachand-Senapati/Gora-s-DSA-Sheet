//like fibonacci as dp
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1; dp[1]=1;//if backtrack from 1 to came 0 and from 0 to came 0 starting index
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//space optimized
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev =1;//if backtrack from 1 to came 0 and from 0 to came 0 starting index
        for(int i=2;i<=n;i++){
            int curri = prev + prev2;
            prev2 = prev; prev = curri;
        }
        return prev;
    }
};