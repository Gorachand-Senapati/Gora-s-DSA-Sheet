class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        stack<int>s;
        int n = arr.size();
        vector<int>ans(n,-1);
        for(int i= 2*n-1;i>=0;i--){
            while(s.size()>0 && arr[s.top()] <= arr[i%n]){
                s.pop();
            }
            ans[i%n]= s.empty()?-1:arr[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};