class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n,1), cnt(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int prev =0;prev<i;prev++){
                if(nums[i] > nums[prev] && dp1[i] < 1+ dp1[prev]){
                    dp1[i] = 1+ dp1[prev];
                    cnt[i] = cnt[prev];//inherit //if came new
                } else if(nums[i] > nums[prev] && dp1[i] == 1+ dp1[prev]){
                    cnt[i]+= cnt[prev];//update cnt;
                }
            }
            if(maxi < dp1[i]){
                maxi = dp1[i];
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(dp1[i] == maxi){
                ans += cnt[i];
            }
        }
        return ans;
    }
};