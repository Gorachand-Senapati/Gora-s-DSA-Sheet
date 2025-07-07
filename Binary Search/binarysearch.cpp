class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int st = 0, end = arr.size() - 1;
        int result = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] < k) {
                st = mid + 1;
            } else if (arr[mid] > k) {
                end = mid - 1;
            } else {
                result = mid;     // store result and go left
                end = mid - 1;
            }
        }

        return result;
    }
};