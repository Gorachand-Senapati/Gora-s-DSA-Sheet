class Solution {
public:
    // const because we won't modify the row
    int upperBound(const vector<int>& row, int target) {
        int low = 0, high = row.size(); // high = size, not size - 1
        while (low < high) {  // FIXED: strict < to prevent out-of-bounds
            int mid = low + (high - low) / 2;
            if (row[mid] <= target) {
                low = mid + 1;//need more upper 
            } else {
                high = mid;
            }
        }
        return low;
    }

    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = mat[0][0];
        int high = mat[0][m - 1];

        // get actual min and max across all rows
        for (int i = 1; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]); 
        }

        int required = (n * m) / 2;

        while (low < high) {  // FIXED: < instead of <=
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < n; i++) {
                count += upperBound(mat[i], mid);
            }

            if (count <= required) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
