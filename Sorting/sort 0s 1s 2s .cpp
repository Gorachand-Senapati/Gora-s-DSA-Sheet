// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n= nums.size();
//         int count0 = 0, count1 = 0, count2= 0;
//         //O(n
//         for(int i=0;i<n;i++){
//             if(nums[i] ==0) count0++;
//             else if(nums[i]==1) count1++;
//             else count2++;
//         }
//         int idx=0;
//         for(int i=0; i<count0; i++ ){
//             nums[idx++] = 0;
//         }
//         for(int i=0; i<count1; i++ ){
//             nums[idx++] = 1;
//         }
//         for(int i=0; i<count2; i++ ){
//             nums[idx++] = 2;
//         }
        
//     }
// };


//optimal
class Solution {
public:
    void sortColors(vector<int>& A) {
        int n= A.size();
       int mid=0, low=0,high= n-1;
       while(mid<=high){
        if(A[mid]==0){ //0
            swap(A[low],A[mid]);
            mid++, low++;
        } else if(A[mid]==1){//1
            mid++;
        } else{ //2
            swap(A[high],A[mid]);
            high--;
        }
       }
        
    }
};