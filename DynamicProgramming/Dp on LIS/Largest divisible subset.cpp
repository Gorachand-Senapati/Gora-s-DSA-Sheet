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
}; // TC: O(N^2) + O(N) for backtracking and SC: O(N) for dp and hash array.


//for gfg need greatest lexicographical order we need to change the condition in line 7 to if(nums[i] % nums[prev] == 0 && dp[i] <= 1 + dp[prev]) and rest of the code will be same.
class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n);

        for(int i=0;i<n;i++){
            dp[i].push_back(arr[i]);

            for(int prev=0;prev<i;prev++){
                if(arr[i] % arr[prev] == 0){
                    vector<int> candidate = dp[prev];
                    candidate.push_back(arr[i]);

                    if(candidate.size() > dp[i].size() ||
                      (candidate.size() == dp[i].size() && candidate > dp[i])){
                        dp[i] = candidate;
                    }
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(dp[i].size() > ans.size() ||
              (dp[i].size() == ans.size() && dp[i] > ans)){
                ans = dp[i];
            }
        }

        return ans;
    }
};
