class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        vector<int> temp(n + m); // create a merged array
        int idx = n + m - 1, i = n - 1, j = m - 1;

        // merge from the end into temp
        while (i >= 0 && j >= 0) {
            if (a[i] > b[j]) {
                temp[idx--] = a[i--];
            } else {
                temp[idx--] = b[j--];
            }
        }

        while (i >= 0) temp[idx--] = a[i--];
        while (j >= 0) temp[idx--] = b[j--];

        return temp[k - 1];
    }
};