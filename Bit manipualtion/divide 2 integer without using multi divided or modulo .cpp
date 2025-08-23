class Solution {
public:
    int divide(int dividend, int divisor) { //22,3
        if(dividend == divisor) return 1;
        //sign check
        bool sign = true;//positive
        if(dividend>=0 && divisor<0) sign= false;
        else if(dividend<0 && divisor>=0) sign= false;
        long n= abs((long)dividend);
        long d= abs((long)divisor);
        divisor= abs(divisor);
       
        long quotient=0;
        while(n>=d){
            int cnt =0;
            while(n >= (d << (cnt+1))) { //d*2^(cnt+1)
                cnt+=1;
            }
            quotient += (1L<<cnt);//2^cnt
            n = n - (d*(1L<<cnt));//22-3*2^2; n=22, d=3, left shift means multiply by 2 to the power k
        }
        //handle overflow
        if(quotient == (1L<<31) && sign){ 
            return INT_MAX; //if the ans is greater than INT_MAX
        }
        //HANDLE underflow
        if(quotient == (1L<<31) && !sign){
            return INT_MIN; //if the ans is less than INT_MIN
        }
        return sign? quotient : -quotient;//if positive return positive else negative
    }
};
