class Solution {
public:
    string removeOuterParentheses(string s) {
        string result= "";
        int balance =0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]== '('){//if see ()
              //check balance
              if(balance > 0){
                result+=s[i];
              }
              balance++;//increase balance (
            } else{
                balance--;// decrease balance for )
                if(balance > 0){
                result+=s[i];
              }
            }
        }
        return result;
    }
};