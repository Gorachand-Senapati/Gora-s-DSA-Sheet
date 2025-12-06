class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int r =1, l=0;
        int ans = 0;
        while(r<n && l<r){
            if((nums[r] - nums[l])==1){
                int sz = r-l+1;
                ans = max(ans,sz);
            }
            while(nums[r] - nums[l] > 1){
                l++;
            }
            r++;
        }
        return ans;
    }
}; //tc O(nlogn) sc O(1)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;//freq store x-> freq
        }
        int ans = 0;
        for(auto &p: freq){
            int x = p.first;
            //check x+1 exist or not in map 
            if(freq.count(x+1)){
                ans = max(ans,freq[x] + freq[x+1]);
            }
        }
        return ans;
    }
};//tc O(n) sc O(n)