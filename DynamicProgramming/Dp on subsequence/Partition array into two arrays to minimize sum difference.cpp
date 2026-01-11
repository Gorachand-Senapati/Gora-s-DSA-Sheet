//recursion 
class Solution {
public:
   bool f(int idx, int cnt,int tar, int k, int totSum, int&mini, vector<int>& nums){
    //base case 1 if cnt == k return mini
     if(cnt == k){
        int s1 = tar;
        int s2 = totSum - s1;
        mini = min(mini, abs(s1-s2));
        return true;
     }
     //out of bound edge case
     if(idx <0) return false;
      bool notTake = f(idx-1, cnt,tar,k,totSum,mini,nums);
      bool take = f(idx-1, cnt+1,tar+ nums[idx],k,totSum,mini,nums);
      return take || notTake;
   }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), totSum =0;
        if(n%2 != 0) return -1;
        for(int x:nums) totSum+= x;
        int k = n/2;
        int mini =1e9;
        f(n-1,0,0,k,totSum,mini,nums);//start not pick last el so cnt =0, tar =0 
        return mini;
    }
};