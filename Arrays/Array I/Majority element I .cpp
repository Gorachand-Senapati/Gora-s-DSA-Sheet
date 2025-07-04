// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // brute force aproch

//         // int n =nums.size();
//         // for(int val:nums) {
//         //     int freq =0;
//         //     for(int el:nums) {
//         //         if(el==val) {
//         //             freq++ ;
//         //         }
//         //     }
//         //     if(freq>n/2){
//         //         return val;
//         //     }
//         // }
//         // return -1;


//         // Better approach APROACH

//         int n =nums.size();

//         sort(nums.begin(), nums.end());

//         //frequency count 

//         int freq =1, ans =nums[0];
//         for(int i=1;i<n;i++) {
//             if(nums[i] == nums[i-1]){
//                 freq ++;
//             } else {
//                 freq =1;
//                 ans =nums[i];
//             }

//             if(freq > n/2){
//                 return ans;
//             }
//         }

//         return ans;




//Moor voting algorithm
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // MOOR voting algorithm
        int n= arr.size();
        int freq =0, ans = 0;
        
        for(int i=0;i<n;i++){
            if(freq == 0){
                ans = arr[i];//1st pick this ans 
            }
            if(ans == arr[i]){
                freq ++;
            } else{
                freq --;
            }
        }
        
        int count = 0;
        for(int i=0; i<n;i++){
            if(i== ans){
                count ++;
            }
        }
        if(count>(n/2)){
            return ans;
        } 
        return -1;
        
    }
};