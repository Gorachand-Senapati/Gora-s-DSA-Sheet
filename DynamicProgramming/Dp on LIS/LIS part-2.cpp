//only n size dp array , intiialize with 1 as min length of LIS is 1 
class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n,1);//intialise with 1
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int prev =0;prev<i;prev++){
                if(arr[prev] < arr[i]){
                    dp[i]=  max(dp[i], 1+ dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

//using binary search O(nlogn)
class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
       vector<int>temp;
       temp.push_back(arr[0]);
       for(int i=1;i<n;i++){
           if(arr[i] > temp.back()){
               temp.push_back(arr[i]);
           }else{
               //if small then find right index to put the elemnet using lower bound
               int idx = lower_bound(temp.begin(), temp.end(), arr[i])
               - temp.begin();
               temp[idx] = arr[i];
               
           }
       }
       return temp.size();
    }
};