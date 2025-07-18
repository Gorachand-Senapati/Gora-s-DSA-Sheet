class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow]; //+1 step move
            fast = nums[nums[fast]]; //+2 step move
        } while(slow != fast);
         
         slow = nums[0];
        while(slow != fast){
            slow = nums[slow]; //+1 step move
            fast = nums[fast]; //+1 step move
        }
        return slow; //because both are meet in duplicate point;
    }
};