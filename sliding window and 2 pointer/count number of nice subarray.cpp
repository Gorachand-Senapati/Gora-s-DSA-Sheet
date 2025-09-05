class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atMost(nums, k) - atMost(nums, k - 1);
    }
 int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int oddCnt = 0, ans = 0;

        while (r < n) {
            if (nums[r] % 2 != 0) oddCnt++;

            while (oddCnt > k) {
                if (nums[l] % 2 != 0) oddCnt--;
                l++;
            }
            ans += (r - l + 1); // all subarrays ending at r
            r++;
        }
        return ans;
    }
};
//Same patten as binary subarray with sum k and also make convert this probelem into binary array if odd then 1 else 0