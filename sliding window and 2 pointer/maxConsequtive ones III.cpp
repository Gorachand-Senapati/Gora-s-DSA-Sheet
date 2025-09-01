class Solution { //O(n) + O(n) = O(2n)
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l =0, r=0, maxLen=0;
        int zeroes=0;
        while(r<n){ //O(n)
            if(nums[r]==0) zeroes++;
            while(zeroes>k){//O(n)
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes<=k){ 
                int len= r-l+1;
                maxLen= max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};

//for make O(n) remove while loop and add if condition for check zeroes>k
class Solution { //O(n)
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l =0, r=0, maxLen=0;
        int zeroes=0;
        while(r<n){
            if(nums[r]==0) zeroes++;
            if(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            int len= r-l+1;
            maxLen= max(maxLen,len);
            r++;
        }
        return maxLen;
    }
};