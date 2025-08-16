class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int res =0; int left=0, right=n-1;
        int leftMax=0, rightMax=0;
        
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(arr[left]>leftMax){
                    leftMax= arr[left];
                } else{
                    res+= leftMax- arr[left];
                }
                left++;
            }else{
                if(arr[right]>rightMax){
                    rightMax= arr[right];
                } else{
                    res+= rightMax- arr[right];
                }
                right--;
            }
        }
        return res;
    }
};