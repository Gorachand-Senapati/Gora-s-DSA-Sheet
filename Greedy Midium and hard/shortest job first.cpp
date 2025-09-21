class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int n= bt.size();
        int t=0, wt=0;//time, waiting time
        for(int i=0;i<n;i++){
            wt+=t;
            t+=bt[i];
        }
        return (wt/n);
    }
};