class Solution{
public:
    vector<vector<int>> primeFactors(vector<int>& queries){
        int MAXN = 100000;// 10^5
        vector<int> spf(MAXN + 1);
        // Initialize spf
        for(int i = 1; i <= MAXN; i++){
            spf[i] = i;// Self-initialization
        }
        // Sieve to compute SPF
        for(int i = 2; i * i <= MAXN; i++){
            if(spf[i] == i){  // i is prime
                for(int j = i * i; j <= MAXN; j += i){ //go up to MAXN
                    if(spf[j] == j){ // not marked before
                        spf[j] = i;//current smallest prime factor
                    }
                }
            }
        }
        vector<vector<int>> ans;
        // Process each query
        for(int q : queries){
            vector<int> factors;
            int n = q;
            while(n != 1){
                factors.push_back(spf[n]);
                n = n / spf[n];//reduce the number
            }
            ans.push_back(factors);
        }
        return ans;
    }
};
