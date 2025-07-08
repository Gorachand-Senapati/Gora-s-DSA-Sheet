class Solution {
public:
    bool isValid(vector<int> &arr, int k, int maxAllocatePage) {
        int student = 1;
        long long pageStudent = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxAllocatePage) return false;

            if (pageStudent + arr[i] <= maxAllocatePage) {
                pageStudent += arr[i];
            } else {
                student++;
                pageStudent = arr[i];
            }
        }

        return student <= k;
    }

    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1; // Not enough books

        int st = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(arr, k, mid)) {
                res = mid;         // Save result and try to find smaller max
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return res;
    }
};
