class Solution {
  public:
 void getAllSubsetsSum(vector<int>& arr,int idx,vector<int>&ans, int sum){
      int n =arr.size();
      if(idx == n){
         ans.push_back(sum);
         return ;
      }

       getAllSubsetsSum(arr,idx+1,ans,sum+arr[idx]);//pick 
       getAllSubsetsSum(arr, idx+1,ans,sum);//not pick
  }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        getAllSubsetsSum(arr,0,ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};