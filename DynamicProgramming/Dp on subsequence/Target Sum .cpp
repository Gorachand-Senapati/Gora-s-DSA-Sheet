class Solution {
public:
    int findWay(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>prev(target+1,0), curr(target+1,0);
        //any time tar =0 base case rturn 1
        if(arr[0] == 0){
            prev[0] =2;//tar =0 and take or nottake
        } else{
            prev[0] =1;//came to last index 
        }
        if(arr[0]!=0 && arr[0] <= target){
            prev[arr[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){//all target need to be covered star from 0 to target bcause we have to fill all dp
                int notTake = prev[tar];
                int take =0;
                if(arr[i]<=tar){
                    take = prev[tar-arr[i]];
                }
                curr[tar] = (notTake + take);
            }
            prev = curr;
        }
        return prev[target];
    }
    int countPartitions(vector<int>& arr, int diff) {
       int n = arr.size(), totSum =0;
       for(int x: arr) totSum+=x;
       if(totSum-diff <0 || (totSum -diff)% 2 != 0) return 0;//need 2 or more no odd
        int target = (totSum-diff)/2;
        return findWay(arr,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //I know 1 part is full positive - 1 part is full negative if diff == target rturn count
        return countPartitions(nums, target);//any process from the partition with given differnce ques memo, tab or space opt
    }
};