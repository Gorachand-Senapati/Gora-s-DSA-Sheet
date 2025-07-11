class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        // vector<int>prefix(n,1);
        // vector<int>suffix(n,1);

    //prefix =>ans
    for(int i=1;i<n;i++){
        // prefix[i]= prefix[i-1] * nums[i-1];
        ans[i]= ans[i-1] * nums[i-1];
    }
    //suffix
    int suffix =1;
    for(int i=n-2;i>=0;i--){
        // suffix[i]= suffix[i+1] * nums[i+1];
        suffix = suffix * nums[i+1];
        ans[i] = ans[i] * suffix;
    }
        
        // for(int i=0;i<n;i++){
        //     ans[i]=  prefix[i]*suffix[i];
        // }

        return ans;
    }
};