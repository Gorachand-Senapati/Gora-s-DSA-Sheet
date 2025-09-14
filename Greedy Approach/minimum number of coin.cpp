class Solution {
  public:
    int findMin(int n) {
        // code here
       vector<int>coins={1,2,5,10};
        int cnt=0;
        for(int i=coins.size()-1;i>=0;i--){
            while(coins[i]<=n){
                n-=coins[i];
                cnt++;
            }
        }
        return cnt;
    }
};