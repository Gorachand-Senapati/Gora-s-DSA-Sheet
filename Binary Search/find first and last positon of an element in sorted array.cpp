class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;  // keep searching left
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                st = mid + 1;  // keep searching right
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
// Another approach 2 pointer
