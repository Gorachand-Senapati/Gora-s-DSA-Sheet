class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // sort(nums);
        int n= nums.size();
        // for(int i=1;i<n;i=i+3){
        //     if(nums[i] != nums[i-1]) return nums[i-1];
        // }
        // return nums[n-1];//incase not find
        int ones=0, twos=0;
        for(int i=0;i<n;i++){
            ones= (ones ^ nums[i]) & ~ twos;
            twos= (twos ^ nums[i]) & ~ ones;
        }
        return ones;
    }
};