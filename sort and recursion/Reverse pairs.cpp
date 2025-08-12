// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n=nums.size(), count =0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if((long long)nums[i] > 2LL * nums[j]) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }
    }

    int countPairs(vector<int>& nums, int l, int r, int mid) {
        int right = mid + 1, cnt = 0;
        for (int i = l; i <= mid; i++) {
            while (right <= r && (long long)nums[i] > 2LL * nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;//base case4
        int mid = l + (r - l) / 2;
        int cnt = 0;
        cnt += mergeSort(nums, l, mid);//left
        cnt += mergeSort(nums, mid + 1, r);//right
        cnt += countPairs(nums, l, r, mid);//modification
        merge(nums, l, mid, r);//merge sort arry
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};