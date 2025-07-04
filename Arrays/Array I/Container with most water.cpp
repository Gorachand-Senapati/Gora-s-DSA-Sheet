class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();

        //brute force
    //     for( int i=0;i<n;i++){
    //     for( int j=i+1;j<n;j++){
    //         int w= j-i;
    //         int ht = min(height[i], height[j]);
    //         int curWater = w*ht;

    //         maxWater = max(maxWater,curWater);


    //     }
    // }
  // optimised approach
    int lp=0, rp = n-1;
    while(lp<rp) {
                 int w= rp-lp;
            int ht = min(height[lp], height[rp]);
            int curWater = w*ht;
            maxWater = max(maxWater,curWater);

            height[lp] <height[rp] ? lp++ : rp--;

    }
    return maxWater;
    };
};