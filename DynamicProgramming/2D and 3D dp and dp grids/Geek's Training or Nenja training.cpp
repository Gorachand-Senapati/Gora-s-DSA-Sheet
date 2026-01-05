//recursion
class Solution {
  public:
  int f(int day, int last,vector<vector<int>>& arr){
      //base case
        if(day == 0){
          int maxi = 0;
          for(int i=0;i<3;i++){
             if(i != last) {
                 maxi = max(maxi,arr[0][i]);
             }
            
          }
           return maxi;
         
        }
      int maxi =0;
         for(int i=0;i<3;i++){//i= task
             if(i != last){
                int point = arr[day][i] + f(day-1, i,arr);
                 maxi = max(maxi,point);
             }
         }
         return maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
       return f(n-1,3,arr);//assume 1st no task choose 3 last task
    }
};

//memoisation
class Solution {
  public:
  int f(int day, int last,vector<vector<int>>& arr, vector<vector<int>>& dp){
      //base case
        if(day == 0){
          int maxi = 0;
          for(int i=0;i<3;i++){
             if(i != last) {
                 maxi = max(maxi,arr[0][i]);
             }
            
          }
           return maxi;
         
        }
        
        if(dp[day][last] != -1) return dp[day][last];
      int maxi =0;
         for(int i=0;i<3;i++){//i= task
             if(i != last){
                int point = arr[day][i] + f(day-1, i,arr,dp);
                 maxi = max(maxi,point);
             }
             
         }
         return dp[day][last] = maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));//because choose 1st time no task perform
       return f(n-1,3,arr,dp);//assume 1st no task choose 3 last task
    }
};

//tabulisation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(4,0));//because choose 1st time no task perform
      //base case day 0 and task
      dp[0][0] = max(arr[0][1], arr[0][2]);
      dp[0][1] = max(arr[0][0], arr[0][2]);
      dp[0][2] = max(arr[0][1], arr[0][0]);
      dp[0][3] = max(arr[0][3],max(arr[0][1], arr[0][2]));///1st no task choose
      
      for(int day =1;day<n;day++){
          for(int last =0;last<4;last++){
              dp[day][last]= 0;//intialise
              for(int task=0;task<3;task++){
                  if(last != task){
                      int point= arr[day][task] + dp[day-1][task];//compute previous
                      dp[day][last]= max(dp[day][last], point);
                  }
              }
          }
      }
      return dp[n-1][3];//for last value
    }
};

//space optimisation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<int>prev(n,0);//because choose 1st time no task perform
      //base case day 0 and task
      prev[0] = max(arr[0][1], arr[0][2]);
      prev[1] = max(arr[0][0], arr[0][2]);
      prev[2] = max(arr[0][1], arr[0][0]);
      prev[3] = max(arr[0][3],max(arr[0][1], arr[0][2]));///1st no task choose
      
      for(int day =1;day<n;day++){
          vector<int>temp(4,0);
          for(int last =0;last<4;last++){
              temp[last] =0;
              for(int task=0;task<3;task++){
                  if(last != task){
                    //   int point= arr[day][task] + dp[day-1][task];//compute previous
                      temp[last]= max(temp[last], arr[day][task] + prev[task]);
                  }
              }
          }
          prev=temp;//now temp is the prev store value
      }
      return prev[3];//for last value
    }
};