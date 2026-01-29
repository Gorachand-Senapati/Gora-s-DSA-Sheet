class Solution { //recursion
public:
    int f(int idx, int n,vector<int>& arr, int k){
        //base case
        if(idx == n) return 0;
        int mxAns =INT_MIN;
        int maxi = INT_MIN, len = 0;
        //go up to k partition which give best
        for(int j = idx;j<min(n,idx+k);j++){//if in last partition make so stop out bound min
            len++;//len increase
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + f(j+1,n,arr,k);//after j
            mxAns = max(mxAns, sum);
        }
        return mxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return f(0,n,arr,k);
    }
};

//memoization

class Solution {
public:
    int f(int idx, int n,vector<int>& arr, int k, vector<int>&dp){
        //base case
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mxAns =INT_MIN;
        int maxi = INT_MIN, len = 0;
        //go up to k partition which give best
        for(int j = idx;j<min(n,idx+k);j++){//if in last partition make so stop out bound min
            len++;//len increase
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + f(j+1,n,arr,k,dp);//after j
            mxAns = max(mxAns, sum);
        }
        return dp[idx] = mxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return f(0,n,arr,k,dp);
    }
};

//tabulation
class Solution {
  public:
    int solve(int n, int k, vector<int>& arr) {
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int idx=n-1;idx>=0;idx--){
            int len=0, maxi = INT_MIN, mxAns = INT_MIN;
            for(int j=idx;j<min(n,idx+k);j++){
                len++; maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j+1];
                mxAns = max(mxAns, sum);
            }
            dp[idx] = mxAns;
        }
        return dp[0];
    }
};