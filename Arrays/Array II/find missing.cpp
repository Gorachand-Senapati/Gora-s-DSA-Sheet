// class Solution {
//   public:
//     int missingNum(vector<int>& arr) {
//         int n = arr.size() + 1;
//         int actualSum = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             actualSum += arr[i];
//         }
//         int expectedSum = (n * (n + 1)) / 2;
//         return expectedSum - actualSum;
//     }
// };

//for long value;
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long expectedSum = (n * (n + 1)) / 2;
        long long actualSum = 0;
        for (int num : arr) {
            actualSum += num;
        }
        return static_cast<int>(expectedSum - actualSum);
    }
};