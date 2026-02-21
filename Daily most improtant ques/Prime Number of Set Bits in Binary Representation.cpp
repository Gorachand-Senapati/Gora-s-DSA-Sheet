//TC= O(N∗Sqrt(Logn))
class Solution {
public:
   bool isPrime(int n){
      if(n <= 1) return false;
      for(int i=2;i<=sqrt(n);i++){//also sqrt(n) === i*i <=n
          if(n%i == 0)return false;
       }
       return true;
   }
   int cntSetBits(int x){ //only cnt set bits not need to convert it in binary
     int cnt =0;
     while(x >0){
        if(x% 2 == 1)cnt++; //if last bit is 1
        x= x/2;//remove the last bit
     }
     return cnt;
   }
    int countPrimeSetBits(int left, int right) {
        int ans =0;
        for(int i=left;i<=right;i++){
            int setBits = cntSetBits(i);//check set bits
            if(isPrime(setBits)) ans++;
        }
        return ans;
    }
};