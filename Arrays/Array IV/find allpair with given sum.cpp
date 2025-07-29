// class Solution {
//   public:
//     // Function to find all pairs with given sum.
//     vector<pair<int, int>> allPairs(int target, vector<int> &a, vector<int> &b) {
//         vector<pair<int, int>> result;

//         for (int i = 0; i < a.size(); i++) {
//             for (int j = 0; j < b.size(); j++) {
//                 if (a[i] + b[j] == target) {
//                     result.push_back({a[i], b[j]});
//                 }
//             }
//         }

//         // Optional: Sort pairs by first then second element
//         sort(result.begin(), result.end());

//         return result;
//     }
// };

class Solution {
  public:
    vector<pair<int, int>> allPairs(int target, vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());  // O(n log n)
        sort(b.begin(), b.end());  // O(m log m)

        vector<pair<int, int>> result;
        int i = 0, j = b.size() - 1;

        while (i < a.size() && j >= 0) {
            int sum = a[i] + b[j];

            if (sum == target) {
                int aVal = a[i], bVal = b[j];

                // Count duplicates of a[i]
                int countA = 0;
                while (i < a.size() && a[i] == aVal) {
                    countA++;
                    i++;
                }

                // Count duplicates of b[j]
                int countB = 0;
                while (j >= 0 && b[j] == bVal) {
                    countB++;
                    j--;
                }

                // Push all combinations of aVal and bVal
                for (int x = 0; x < countA; ++x) {
                    for (int y = 0; y < countB; ++y) {
                        result.push_back({aVal, bVal});
                    }
                }
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return result;
    }
};

