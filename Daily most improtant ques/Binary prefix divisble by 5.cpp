class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int rem =0;
        for(int bit: nums){ //nums[i]=bit
            rem = (rem* 2 + bit) %5;//update reminder if 0 then push in ans
            ans.push_back(rem==0);
        }
        return ans;
    }
};