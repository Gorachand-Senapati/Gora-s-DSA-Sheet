class Solution {
public:
    void helper(int idx, int target, vector<int>& candidates,
                vector<int>& path, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(path); // ✅ Valid combination
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
    // 1. Skip duplicates on the same recursion level
    if (i > idx && candidates[i] == candidates[i - 1]) continue;

    // 2. If number is bigger than target, break (array is sorted)
    if (candidates[i] > target) break;

    // 3. Include current number in path
    path.push_back(candidates[i]);

    // 4. Move to the next index (i + 1), because we can't reuse same element
    helper(i + 1, target - candidates[i], candidates, path, result);

    // 5. Backtrack (remove last element and try next)
    path.pop_back();
}

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        // ✅ Sort to handle duplicates easily
        sort(candidates.begin(), candidates.end());

        helper(0, target, candidates, path, result);
        return result;
    }
};