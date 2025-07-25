class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
         vector<vector<int>>ans;
         int n = intervals.size();
         for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);//here if not same back last element compare with i first elment
            } else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);//expand if overlap
            }
         }
        return ans;
    }
};