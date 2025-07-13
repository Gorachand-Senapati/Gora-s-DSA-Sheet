//Brute force approach
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

//optimised Binary search
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        
        // Always binary search on the smaller array
        if (n > m) return kthElement(b, a, k);
        
        int left = k;
        int low = max(0, k - m);     
        int high = min(n, k);         

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n) r1 = a[mid1];   
            if (mid2 < m) r2 = b[mid2];   

            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return -1; 
    }
};