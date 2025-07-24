class Solution {
public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // Base case: one element
        if (l >= r) return;

        // Divide
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);        // Left half
        mergeSort(arr, mid + 1, r);    // Right half

        // Combine
        merge(arr, l, mid, r);
    }

private:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        // Merge the two sorted halves
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // Remaining elements of left half
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements of right half
        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }
// l= Start index of the subarray being merged 
        // Copy sorted temp back to original array
        for (int k = 0; k < temp.size(); k++) {
            //1st copy from last subarray so 
            arr[l + k] = temp[k];
        }
    }
};