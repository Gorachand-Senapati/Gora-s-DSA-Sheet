class Solution {
public:
   bool checks(vector<int>&nums, int i, int count, int dir){
    int idx = i;//idx= curr according ques
    vector<int>temp= nums;//create a copy of nums for changing
    while(idx >=0 && idx< nums.size() && count >0 ){
        if(temp[idx] > 0){
            temp[idx]--;//decrease value 1
            dir*= -1;//for go left or right
            if(temp[idx] == 0){
                count--;
            }
        }
        idx+= dir;//go direction
    }
    return count == 0;//all count now 0
   }
    int countValidSelections(vector<int>& nums) {
        int ans = 0, n= nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                count++;//1st store how many non 0 value
            }
        }
        //here I use dir if go right +1 if left -1 so use -1 multiply for changing
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
               if(checks(nums, i, count, -1)){
                  ans++;
               }  //left
               if(checks(nums, i, count, 1)){
                  ans++;
               }  //right
            }
        }
        return ans; //O(n^2)
    }
};

// Optimised Approach
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum =0, ans =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            if(nums[i]==0){
                int leftSum=currSum;
                int rightSum= sum- leftSum;
                if(leftSum == rightSum){//if go left right
                    ans+=2;
                }else if(abs(leftSum - rightSum) == 1){//only go right
                    ans+=1;
                }
            }
        }
        return ans;
    }
};