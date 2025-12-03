//bfa
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        vector<long long >prefixSum(n+1,0);//make a prefix sum int initialize 0
        for(int i=0;i<n;i++){
            prefixSum[i+1]= prefixSum[i] + nums[i];
        }
        long long ans = LLONG_MIN;
        //try all subarray
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(len % k == 0){
                    long long sum = prefixSum[j+1]- prefixSum[i];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};