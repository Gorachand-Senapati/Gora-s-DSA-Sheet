// User function Template for C++

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        int totsubsets = (1 << n); // 2^n
        vector<vector<int>> ans;

        for (int num = 0; num < totsubsets; num++) {
            vector<int> list;
            for (int j = 0; j < n; j++) {
                // check if jth bit is set
                if ((num & (1 << j)) != 0) {
                    list.push_back(arr[j]);
                }
            }
            ans.push_back(list); // push this subset
        }
        // sort subsets so order is [] , 1 , 1 2 , 1 2 3 , 1 3 , 2 , 2 3 , 3
        // sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
        //     if (a.empty() && b.empty()) return false;  // keep [] first
        //     if (a.empty()) return true;
        //     if (b.empty()) return false;
        //     // lexicographic order
        //     return a < b;
        // });
        return ans;
    }
};
