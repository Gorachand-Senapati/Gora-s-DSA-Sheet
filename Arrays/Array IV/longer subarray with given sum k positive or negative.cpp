//Better Approach here TC= O(n logn) if use ordered map
//TC= O(n*n) if use unordered map for search all element in map and SC= O(n) for store
//And it also works for negative numbers
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long, int>preSum;
        int maxLen=0, prefixSum=0;
        for(int i=0;i<arr.size();i++){
            prefixSum+=arr[i];
            if(prefixSum == k) maxLen= max(maxLen,i+1);
            int rem= prefixSum-k;
            if(preSum.find(rem) != preSum.end()){//if find
              int len= i- preSum[rem];
              maxLen= max(len, maxLen);
            }
            if(preSum.find(prefixSum) == preSum.end()){
                preSum[prefixSum]=i;
            }
        }
        return maxLen;
    }
};

//optimal for positive numbers TC O(2n) works only positive 
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = 0;
        long long sum = 0;
        int maxLen = 0;

        while (right < n) {
            sum += arr[right];
            // shrink window until sum <= k
            while (left <= right && sum > k) {
                sum -= arr[left];
                left++;
            }

            // check if sum equals k
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};