class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);//size =n+1 means 0 to n all assume true
        int ans =0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                ans++;
                //multiply out korbo
                for(int j=i*2;j<n;j= j+i){
                    isPrime [j]= false;
                }
            }
         
        }
           return ans;
    }
};

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<int> ans;

        // Sieve of Eratosthenes up to N
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect primes in the range [M, N]
        for (int i = max(2, M); i <= N; i++) {
            if (isPrime[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int ans =0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                ans++;
                //multiply out korbo
                for(int j=i*2;j<n;j= j+i){
                    isPrime [j]= false;
                }
            }
         
        }
           return ans;
    }
};
