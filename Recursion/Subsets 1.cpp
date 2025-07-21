class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int> & ans, int i, vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            //store ans
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]); //include
        getAllSubsets(nums, ans, i+1,allSubsets);

        ans.pop_back();//backTracking

        //exclude
        getAllSubsets(nums, ans, i+1, allSubsets);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        vector<int>ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
}

};