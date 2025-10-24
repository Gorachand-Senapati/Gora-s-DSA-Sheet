class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h = nums.size()-1;
        while(l<h){
            int mid = l + (h-l)/2;
            if(nums[mid] > nums[h]){//min present in right side
                l= mid+1;
            } else{
                h= mid;
            }
        }
        return nums[l];
    }
};