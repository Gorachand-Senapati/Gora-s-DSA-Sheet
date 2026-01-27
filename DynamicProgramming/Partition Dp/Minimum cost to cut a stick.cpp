class Solution {
public:
   int f(int i, int j, vector<int>& cuts){
       if(i >j) return 0;
       int mini = INT_MAX;
       for(int idx = i;idx<=j;idx++){
           int cost = cuts[j+1] - cuts[i-1];
           int left = f(i, idx-1, cuts);
           int right = f(idx+1, j, cuts);
           mini = min(mini, cost + left + right);
       }
     return mini;
   }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);//last size push back
        cuts.insert(cuts.begin(), 0);//in front 0 
        sort(cuts.begin(), cuts.end());
        return f(1,c, cuts);
    }
};

//memoization
class Solution {
public:
   int f(int i, int j, vector<int>& cuts, vector<vector<int>>&dp){
       if(i >j) return 0;
       int mini = INT_MAX;
       if(dp[i][j] != -1) return dp[i][j];
       for(int idx = i;idx<=j;idx++){
           int cost = cuts[j+1] - cuts[i-1];
           int left = f(i, idx-1, cuts,dp);
           int right = f(idx+1, j, cuts,dp);
           mini = min(mini, cost + left + right);
       }
     return dp[i][j] = mini;
   }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>>dp(c+1, vector<int>(c+1,-1));
        cuts.push_back(n);//last size push back
        cuts.insert(cuts.begin(), 0);//in front 0 
        sort(cuts.begin(), cuts.end());
        return f(1,c, cuts,dp);
    }
};

//tabulation
class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>>dp(c+2, vector<int>(c+2,0));//base case include
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        //changing paremeter 
        for(int i=c; i>=1;i--){// i traverses backward from c to 1
            for(int j=i;j<=c;j++){// j traverses forward from i to c
                int mini = INT_MAX;
                for(int idx= i;idx<=j;idx++){
                    int cost = cuts[j+1] - cuts[i-1];
                    int left = dp[i][idx-1];
                    int right = dp[idx+1][j];
                    mini = min(mini, cost+left+right);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};