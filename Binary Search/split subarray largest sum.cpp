class Solution {
public:
//its a similar question book allocation problem
bool isValid(vector<int>& nums, int k,int n, int largestSum){//map= mid
    int subarr = 1, sums =0;
    for(int i=0; i<n;i++){
     if( nums[i] > largestSum){//edge case
        return false;
     }

     if(sums + nums[i] <= largestSum){
        sums += nums[i];
     } else{
        subarr++;
        sums = nums[i];
     }
    }
    //abar student jodi k theke besi hoy tahole invalid noyto valid
    return subarr > k ? false: true;
}

    int splitArray(vector<int>& nums, int k) {
       
        int n = nums.size();
         if(k>n) {
            return -1;
            }
        int sum = 0;
        for(int i= 0;i<n; i++){
            sum+= nums[i];
        }
        int st = 0, end= sum, ans = -1;
        while(st<=end){
            int mid= st+ (end-st)/2;
            if(isValid(nums,k,n,mid)){//left search
            ans = mid;
            end = mid -1;
            } else {//right search
              st = mid+1;
            }
        }

        return ans;
    }
};