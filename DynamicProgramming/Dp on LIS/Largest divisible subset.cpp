class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1), hash(n);
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN, lastIdx = 0;
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int prev =0;prev<i;prev++){//need check from 0 idx
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]){//length increase by 1 
                  dp[i] = 1 + dp[prev];
                  hash[i]= prev;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        //now backtrack and print the subsequece 
        vector<int>temp;
        temp.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
             temp.push_back(nums[lastIdx]);;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};