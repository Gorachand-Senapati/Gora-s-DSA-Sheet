class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx,
                vector<int>& path, vector<vector<int>>& ans) {
        int n = candidates.size();

        // ✅ Base case: target reached
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        // ❌ Invalid case: index out of bounds or target negative
        if (idx == n || target < 0) return;

        // ✅ Choice 1: Take the current element (reuse allowed, so idx remains same)
        if (candidates[idx] <= target) {
            path.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], idx, path, ans);
            path.pop_back(); // backtrack
        }

        // ✅ Choice 2: Skip the current element (move to next idx)
        helper(candidates, target, idx + 1, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        helper(candidates, target, 0, path, ans);
        return ans;
    }
};
