class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n= val.size();
        vector<pair<double, int>>ratio;//{val/wt, index}
        for(int i=0;i<n;i++){
            ratio.push_back({(double)val[i]/wt[i],i});//val/wt,idx stor the ratio array
        }
        sort(ratio.rbegin(), ratio.rend());// sort by ratio descending
        double maxVal=0.0;
        for(auto &p: ratio){
            int idx= p.second;
            if(capacity>=wt[idx]){
                maxVal+=val[idx];
                capacity-=wt[idx];
            } else{
                maxVal+= (double)val[idx] * capacity/wt[idx];
                break;
            }
        }
        return maxVal;
    }
};
