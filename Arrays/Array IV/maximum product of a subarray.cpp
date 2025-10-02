class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currProd= 1;
        int maxProd= INT_MIN;
        for(int i=0;i<n;i++){//left to right
            currProd*=nums[i];
            maxProd= max(maxProd, currProd);
            if(currProd==0){
                currProd=1;
            }
        }
        currProd=1;
        for(int i=n-1;i>=0;i--){//right to left
            currProd*=nums[i];
            maxProd= max(maxProd, currProd);
            if(currProd==0){
                currProd=1;
            }
        }
        return maxProd;
    }
};