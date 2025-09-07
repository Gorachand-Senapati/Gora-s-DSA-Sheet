class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int,int> freq; // count freq of each number in subarray
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) distinct++; // new distinct number
                freq[nums[j]]++;

                if (distinct == k) ans++;       // valid subarray
                else if (distinct > k) break;   // too many distinct → stop early
            }
        }
        return ans;
    }
};


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)- atmost(nums,k-1);
    }
    int atmost(vector<int>& nums, int k){
        int n= nums.size();
        map<int, int>mpp;
        int r=0, l=0, cnt=0, sum=0;
        while(r<n){
          mpp[nums[r]]++;
            while(l<=r && mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};