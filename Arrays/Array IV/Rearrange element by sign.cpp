class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            } else{
                neg.push_back(nums[i]);
            }
        }
        int l=0, r=0;//2 pointer
        vector<int>ans;
        int m= pos.size();
        while(l<m){
            ans.push_back(pos[l]);
            ans.push_back(neg[l]);
            l++;r++;
        }
        return ans;
    }
};

//another approach reduce space

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // Initializing an answer array of size n
        vector<int> ans(n, 0);
        // Initializing two pointers to track even and odd indices for positive and negative integers respectively
        int posIndex = 0, negIndex=1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                // Placing the positive integer at the  desired index in ans and incrementing posIndex by 2
                ans[posIndex] = nums[i];
                posIndex+=2;
            } else {
                // Placing the negative integer at the  desired index in ans and incrementing negIndex by 2
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};