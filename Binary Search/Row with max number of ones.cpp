//BFA:

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size(), m = arr[0].size();//row & col size
        int idx = -1;
        int maxCnt = -1;
        for (int i=0;i<n;i++){
            int cntRow = 0;
            for(int j=0;j<m;j++){
                cntRow+=arr[i][j];
            }
            if(cntRow > maxCnt){
                maxCnt = cntRow;
                idx = i;
            }
        }
        return idx;
    }
};
//using binary search
// User function template for C++
class Solution {
  public:
   int lowerBound(vector<int>&arrs, int n, int x){ //n= size of the array, x = which val lower bound need
    int ans =n;//assume 1st that n is my lowwer bound
    int low =0 , high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arrs[mid] >= x){
            ans = mid;//store it is my ans 
            high = mid-1;//need more left if exist
        } else{
            low = mid+1;
        }
    }
     return ans;
   };
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size(), m = arr[0].size();//row & col size
        int idx = -1;
        int maxCnt = 0;
        for (int i=0;i<n;i++){
          int count_onesRow = m - lowerBound(arr[i],m,1);//for single row, size - lower bound,need for 1
            if(count_onesRow > maxCnt){
                maxCnt = count_onesRow ;
                idx =i;
            }
        }
        return idx;
    }
};