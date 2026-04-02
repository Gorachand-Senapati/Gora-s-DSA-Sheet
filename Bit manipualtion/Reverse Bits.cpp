class Solution {
public:
    int reverseBits(int n) {
         int res = 0;

        // Repeat exactly 32 times (fixed width integer).
        for (int i = 0; i < 32; ++i) {
            // Shift result left and append least-significant bit of n.
            res = (res << 1) | (n & 1);//in decimal = res*10+ n%10; so here base 2

            // Move n right to expose next bit.
            n >>= 1; //n = n/10
        }

        return res;
    }
};