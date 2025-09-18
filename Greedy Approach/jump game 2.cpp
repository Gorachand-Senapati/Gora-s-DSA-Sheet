class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0, l=0, r=0;//keep a range l= min and r= max
        int n= nums.size();
        while(r<n-1){
            int farther=0;
            for(int idx=l;idx<=r;idx++){
                farther= max(idx+nums[idx], farther);
            }
            l= r+1;
            r= farther;
            jumps= jumps+1;
        }
        return jumps;
    }
};
// BFA
class Solution {
public:
    int minJumps(vector<int>& nums, int idx, int jumps) {
        int n = nums.size();
        
        // Base case: if we reached or crossed the last index
        if (idx >= n - 1) return jumps;

        int mini = INT_MAX;

        // Try all possible jumps from current index
        for (int step = 1; step <= nums[idx]; step++) {
            mini = min(mini, minJumps(nums, idx + step, jumps + 1));
        }

        return mini;
    }

    int jump(vector<int>& nums) {
        return minJumps(nums, 0, 0);
    }
};// Time Complexity: O(N^N) , Space Complexity: O(1)// Time Complexity: O(N^2) , Space Complexity: O(1) for dp approach