class Solution {
public:
  int sumByd(vector<int>& nums, int divisor){
    int sum =0;
    for(int i=0;i<nums.size();i++){
        sum= sum + ceil((double) (nums[i]) / (double) (divisor));
    }
    return sum;
  }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1, high= *max_element(nums.begin(), nums.end());//alsway divisor stay in this range
        while(low<= high){
            int mid = low + (high- low)/2;
            if(sumByd(nums, mid) <= threshold){
                //need more small so go left
                high = mid-1;
            } else {
                low= mid+1;
            }
        }
        return low;
    }
};