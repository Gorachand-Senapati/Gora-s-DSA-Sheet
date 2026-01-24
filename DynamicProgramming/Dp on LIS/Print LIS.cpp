class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>dp(n,1), hash(n);//intialise with 1
        int maxi = 0, lastIdx = 0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev =0;prev<i;prev++){
                if(arr[prev] < arr[i] && 1+ dp[prev] >dp[i]){
                    dp[i]=   1+ dp[prev];
                    hash[i]= prev;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};