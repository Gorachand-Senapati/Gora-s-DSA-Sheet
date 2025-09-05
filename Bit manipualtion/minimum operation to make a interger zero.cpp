class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;
        while(true){//untill give a valid ans or a negative value
            long long val= (long long)num1 - (long long )t * num2;
            if(val<0) return -1;//negative never reached 0
            if(__builtin_popcountll(val) <= t && t<= val){ //__builtin_popcountll(val) used for find bits
                return t;
            }
            t++;
        }
        return -1;
    }
};
//if create limits of t then it maximum go upto 35
//as 2^35 is greater than 10^9
//so we can also use for loop from 0 to 35 instead of while loop
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
       for(int t=1;t<=36;t++){
            long long val= (long long)num1 - (long long )t * num2;
            if(val<0) return -1;//negative never reached 0
            if(__builtin_popcountll(val) <= t && t<= val){ //__builtin_popcountll(val) used for find bits
                return t;
            }
        }
        return -1;
    }
};
//time complexity is O(1) as t maximum go upto 35