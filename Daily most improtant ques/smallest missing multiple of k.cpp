class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int x=k;
        for(int i: nums){
            if(i==x) x=x+k;
        }
        return x;
    }
};