class Solution {
  public:
  
    int inversionCount(vector<int> &arr) {
        return inversionCountUtil(arr, 0, arr.size() - 1);
    }
    
    int inversionCountUtil(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        int leftInvcnt = inversionCountUtil(arr, l, mid);       // Left half
        int rightInvcnt = inversionCountUtil(arr, mid + 1, r);   // Right half

        int invCount = merge(arr, l, mid, r); // Count cross inversions
        return leftInvcnt + rightInvcnt + invCount;
    }
    
    int merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;
        int invCount = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                invCount += (mid - i + 1);  // All remaining elements in left half are greater
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }

        return invCount;
    }
};