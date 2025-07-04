class Solution {
public:
    double myPow(double x , int n) {
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(n == 0) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;

        if(x == -1 && n%2 != 0) return -1.0;
        long dtbin = n; //decimal to binary 
        if(n<0){
            x = 1/x;
            dtbin = -dtbin;
        };
        double ans = 1;

        while(dtbin > 0) {
            if(dtbin % 2 == 1) {
                ans = ans * x;
            };
            x *= x; //x^2
            dtbin = dtbin/2; //decimal to binary convert;
        }
        return ans;
    }
};