//recursion
// User function Template for C++
class Solution {
  public:
    int f(int i, int j,int isTrue,string &s){
        //base case
        if(i >j) return 0;
        if(i == j){//if 1 element
            if(isTrue == 1){
                return s[i]=='T' ? 1:0;//if T then 1 else 0 if isTrue value is 1
            }else{
                return s[i] == 'F' ? 1:0;//if F then 1 else 0 if isTrue value is 0;
            }
        }
        int ways = 0;
        for(int idx = i+1;idx<=j-1;idx+=2){//every 2 index have a operator
            //recursively check how  the number of ways to make the left and right subexpressions true or false
            int lt = f(i,idx-1,1,s);// Number of ways to make the left expression true.
            int lf = f(i,idx-1,0,s);// Number of ways to make the left expression false.
            int rt = f(idx+1,j,1,s);// Number of ways to make the left expression true.
            int rf = f(idx+1,j,0,s);// Number of ways to make the left expression false.
            
            //check the operator and current indx change accordingly
            if(s[idx] == '&'){
                if(isTrue == 1) ways = ways+ (lt*rt);//only both true then true
                else ways = ways + (lt *rf) + (lf*rt) +(lf * rf);
            }else if(s[idx] == '|'){//or
                if(isTrue == 1) ways = ways+ (lt*rt)+ (lt *rf) + (lf*rt);
                else ways = ways + (lf * rf);
            }else {
                 if(isTrue == 1) ways = ways+ (lt *rf) + (lf*rt);
                else ways = ways + (lt*rt) + (lf * rf);
            }
            
        }
        return ways;
    }
    int countWays(string &s) {
        int n = s.size();
        return f(0, n-1,1,s);//// Start evaluation with isTrue set to 1 true.
    }
};

//memoization
// User function Template for C++
class Solution {
  public:
    int f(int i, int j,int isTrue,string &s, vector<vector<vector<int>>>&dp){
        //base case
        if(i >j) return 0;
        if(i == j){//if 1 element
            if(isTrue == 1){
                return s[i]=='T' ? 1:0;//if T then 1 else 0 if isTrue value is 1
            }else{
                return s[i] == 'F' ? 1:0;//if F then 1 else 0 if isTrue value is 0;
            }
        }
         if(dp[i][j][isTrue]!= -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int idx = i+1;idx<=j-1;idx+=2){//every 2 index have a operator
            //recursively check how  the number of ways to make the left and right subexpressions true or false
            int lt = f(i,idx-1,1,s,dp);// Number of ways to make the left expression true.
            int lf = f(i,idx-1,0,s,dp);// Number of ways to make the left expression false.
            int rt = f(idx+1,j,1,s,dp);// Number of ways to make the left expression true.
            int rf = f(idx+1,j,0,s,dp);// Number of ways to make the left expression false.
            
            //check the operator and current indx change accordingly
            if(s[idx] == '&'){
                if(isTrue == 1) ways = ways+ (lt*rt);//only both true then true
                else ways = ways + (lt *rf) + (lf*rt) +(lf * rf);
            }else if(s[idx] == '|'){//or
                if(isTrue == 1) ways = ways+ (lt*rt)+ (lt *rf) + (lf*rt);
                else ways = ways + (lf * rf);
            }else {
                 if(isTrue == 1) ways = ways+ (lt *rf) + (lf*rt);
                else ways = ways + (lt*rt) + (lf * rf);
            }
            
        }
        return dp[i][j][isTrue] =  ways;
    }
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0, n-1,1,s,dp);//// Start evaluation with isTrue set to 1 true.
    }
};

//tabulation

// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int i= n-1;i>=0;i--){
            for(int j=i;j<n;j++){//also j can start from 0 accepted
                //base case1
                if(i >j) continue;
               for(int isTrue =0;isTrue<=1;isTrue++){
                    //base case 2- if i==j evalute the single character
                 if(i==j){
                    if(isTrue ==1) dp[i][j][isTrue] = s[i]=='T';
                    else dp[i][j][isTrue] = s[i]=='F';
                    continue;
                 }
               
               int ways =0;
         for(int idx = i+1;idx<=j-1;idx+=2){//every 2 index have a operator
            //recursively check how  the number of ways to make the left and right subexpressions true or false
            int lt = dp[i][idx-1][1];// Number of ways to make the left expression true.
            int lf = dp[i][idx-1][0];// Number of ways to make the left expression false.
            int rt = dp[idx+1][j][1];// Number of ways to make the left expression true.
            int rf = dp[idx+1][j][0];// Number of ways to make the left expression false.
            
            //check the operator and current indx change accordingly
            if(s[idx] == '&'){
                if(isTrue == 1) ways = ways+ (lt*rt);//only both true then true
                else ways = ways + (lt *rf) + (lf*rt) +(lf * rf);
            }else if(s[idx] == '|'){//or
                if(isTrue == 1) ways = ways+ (lt*rt)+ (lt *rf) + (lf*rt);
                else ways = ways + (lf * rf);
            }else {
                 if(isTrue == 1) ways = ways+ (lt *rf) + (lf*rt);
                else ways = ways + (lt*rt) + (lf * rf);
            }
            
         }
          dp[i][j][isTrue] =  ways; 
            }
        }
        }
        return dp[0][n-1][1];//// Start evaluation with isTrue set to 1 true.
    }
};