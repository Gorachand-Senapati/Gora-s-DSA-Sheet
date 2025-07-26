class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n= arr.size();
        unordered_map<int, int>mpp;
        int sum =0, maxLen =0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum == 0){
                maxLen =i+1;
            } else if(mpp.find(sum) != mpp.end()){//get sum value
                maxLen = max(maxLen, i- mpp[sum]);
            } else{
                mpp[sum]=i;
            }
        }
        return maxLen;
    }
};