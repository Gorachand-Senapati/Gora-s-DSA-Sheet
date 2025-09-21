// BFA O(n2) SC= O(1)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int platforms = 1; // at least one train needs one platform
        
        for (int i = 0; i < n; i++) {
            int cnt = 1; // current train
            
            for (int j = i + 1; j < n; j++) {
                // overlap condition
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || 
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    cnt++;
                }
            }
            platforms = max(platforms, cnt);
        }
        
        return platforms;
    }
};

// Optimal O(nlogn +n) SC= O(1)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int cnt = 0, platforms = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { // train arrives before next departs
                cnt++;
                platforms = max(platforms, cnt);
                i++;
            } else { // train departs
                cnt--;
                j++;
            }
        }
        return platforms;
    }
};

