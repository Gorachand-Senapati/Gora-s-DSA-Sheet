class Solution {
public:
 static bool comp(const vector<int> &val1, const vector<int>&val2){
    return val1[1] < val2[1];
 }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int cnt=1, endTime= intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= endTime){
                cnt++;
                endTime= intervals[i][1];
            }
        }
        return n-cnt;
    }
};// Time Complexity: O(nlogn)+ O(n) for sorting
// Space Complexity: O(1)