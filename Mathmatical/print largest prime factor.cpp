class Solution {
  public:
    int largestPrimeFactor(int n) {
        vector<int>ans;
        for(int i=2;i*i<=n;i++){ // iterate from 2 to sqrt(n) i^2=n so i= root(n)
            if(n % i ==0) ans.push_back(i);
            while(n % i ==0){
                n= n/i;//reduce the number
            }
            if(n != 1)ans.push_back(n);
        }
        return ans.back();//bcz last is the largest prime
    }
};