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

// using Kadans Algorithm
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
         vector<long long>preSum(n);
         preSum[0]=nums[0];
         for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + nums[i];
         }

         long long result = LLONG_MIN;
//using kadans algo
         for(int start =0;start<k;start++){
            long long currSum = 0;

            int i = start;
        while(i <n && i+ k-1 < n){
            int j = i+k -1;
            long long subSum = preSum[j] - (i > 0 ? preSum[i-1] : 0);
            //use kadanes
            currSum = max(subSum, currSum + subSum);//new sub good ? or combine good
            result = max(result, currSum);
            i= i+k;
        }
            
         }
         return result;
    }
};