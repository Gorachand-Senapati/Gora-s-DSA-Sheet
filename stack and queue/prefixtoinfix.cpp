// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
              int n= pre_exp.size(), i=n-1;
        stack<string>st;
        while(i>=0){
            char c= pre_exp[i];
            //if operand find normal push in stack
            if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                st.push(string(1,c));//char when push stack need string
            } else{
                    string t1= st.top(); st.pop();
                    string t2= st.top(); st.pop();
                 string ans = "(" + t1 + string(1, c) + t2 + ")";  //orrect order + string(1, c) here TC O(n1)+O(n2) bcz n1 1st string length..
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};