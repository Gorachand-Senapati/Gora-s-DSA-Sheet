//using prefix sum TC & SC= O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1; // empty prefix sum
        int sum = 0, cnt = 0;
        for (int x : nums) {
            sum += x;
            // if prefix sum "sum - goal" exists, then we found subarrays ending here
            if (freq.count(sum - goal)) {
                cnt += freq[sum - goal];
            }
            freq[sum]++;
        }
        return cnt;
    }
};

//using sliding window TC= O(n) SC= O(1) two pass using recursion
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int goal) {
        int left = 0, right = 0, sum = 0, count = 0;
        if(goal<0) return 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (left <= right && sum > goal) {
                sum -= nums[left++];
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};
