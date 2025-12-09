class Solution {
public:
    int countTriples(int n) {
        int res =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k = int(sqrt((double) i * i + (double) j*j));//find squre root value
                if(k<=n && k * k == i*i + j*j){
                     res++;
                }
            }
        }
        return res;
    }
};