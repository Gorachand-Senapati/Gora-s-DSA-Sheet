class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
    
        int st = 0, end = n-1;

        while(st<end){
            int mid = st+ (end-st)/2;
            
 if(nums[mid+1]<nums[mid]){
                end = mid;
            } else{
               st = mid+1;
            }
        }
        return st;
    }
};