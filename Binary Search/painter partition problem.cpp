class Solution {
  public:
    bool isValid(vector<int> &arr, int k, int maxBoard) {
        int painter = 1;
        int currSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxBoard) return false;

            if (currSum + arr[i] <= maxBoard) {
                currSum += arr[i];
            } else {
                painter++;
                currSum = arr[i];
            }
        }

        return painter <= k;
    }

    int minTime(vector<int> &arr, int k) {
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int res = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(arr, k, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return res;
    }
};