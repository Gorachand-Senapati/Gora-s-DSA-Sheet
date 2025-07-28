// class Solution {
//   public:
//     long subarrayXor(vector<int> &arr, int k) {
//         // code here
//         int n = arr.size(), count =0;
//         for(int i=0;i<n;i++){
//             int xorr =0;
//             for(int j=i;j<n;j++){
//                 xorr = xorr^arr[j];
//                 // for(int k=i;k<=j;k++){
//                 //     xorr = xorr^ arr[k];
//                 // }
//                 if(xorr == k){
//                     count ++;
//                 }
                
//             }
//         }
//         return count;
//     }
// };

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size(), count =0;
        int xr = 0;
      unordered_map<int, int>mpp;
        mpp[xr]++;// 0 store 1st time 1
        for(int i=0;i<n;i++){
            xr= xr^ arr[i];//previous xor and current array value 
            //formula
            int x = xr^k;// General formula find x 
            count += mpp[x];//here count + how much time it has
            mpp[xr]++; //xr current value with how much time appear
        }
        return count;
    }
};