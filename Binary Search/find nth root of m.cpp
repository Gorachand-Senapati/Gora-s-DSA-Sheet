class Solution {
  public:
  
  long long pow(int x, int n) {
      long long ans =1;
      long long base =x;
      
      while(n >0){
          if(n %2 ==1){
              ans *= base;
              if(ans > 1e9) {return ans;}//early break for prevent overflow
          }
          base *= base;
          if (base > 1e9) return base;
          n /=2;
      }
      return ans;
  }
    int nthRoot(int n, int m) {
        // Code here.
        int st = 1, end = m;
        
        while(st<= end ) {
            int mid = st + (end - st)/2;
            
            if(pow(mid,n) == m){
                return mid;
            } else if(pow(mid, n) > m){
                end = mid -1;
            } else {
                st = mid +1;
            }
        }
        return -1;
    }

// striver

// int func(int mid, int n, int m) {
//     long long ans = 1;
//     for (int i = 1; i <= n; i++) {
//         ans = ans * mid;
//         if (ans > m) return 2;
//     }
//     if (ans == m) return 1;
//     return 0;
// }

// int nthRoot(int n, int m) {
//     //Use Binary search on the answer space:
//     int low = 1, high = m;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int midN = func(mid, n, m);
//         if (midN == 1) {
//             return mid;
//         }
//         else if (midN == 0) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }
// };