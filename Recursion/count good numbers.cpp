class Solution {
public:
      long long mod = 1e9 +7;

      long long power(long long x, long long n){//binary exponentaitions
        long long res =1;
        while(n > 0){
            if(n %2 == 1) res = (res * x) % mod;//odd
            x = (x * x) % mod;//even
            n = n/2;
        }
        return res;//shift right in  binary (n >>1)
      }
    int countGoodNumbers(long long n) {
        
         long long even = (n+1)/2;//even idx
         long long odd = n/2;//even idx

         long long ans = (power(5, even ) * power(4, odd)) % mod;
         return ans;

    }
};