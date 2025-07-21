 //for unique solution
class Solution {
public:
    void getperms(string &s, int idx, set<string> &unique) {
        if(idx == s.length()) {
            unique.insert(s);
            return;
        }

        for(int i = idx; i < s.length(); i++) {
            swap(s[idx], s[i]);
            getperms(s, idx + 1, unique);
            swap(s[idx], s[i]); // backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        set<string> unique;
        getperms(s, 0, unique);
        return vector<string>(unique.begin(), unique.end()); // convert to vector
    }
};


//for number
class Solution {
public:
  void getPerms(vector<int>& nums, int idx,  vector<vector<int>>& ans) {
    if(idx == nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int i= idx; i<nums.size(); i++) {
        swap(nums[idx], nums[i]);// idx place ith element
        getPerms(nums, idx+1, ans);

        swap(nums[idx], nums[i]); //backtracking
    }
  }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
         getPerms(nums, 0, ans);
         return ans;
        
    }
};