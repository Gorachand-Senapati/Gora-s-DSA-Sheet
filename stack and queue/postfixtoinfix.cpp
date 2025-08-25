// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        int n= exp.size(), i=0;
        stack<string>st;
        while(i<n){
            char c= exp[i];
            //if operand find normal push in stack
            if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                st.push(string(1,c));//char when push stack need string
            } else{
                    string t1= st.top(); st.pop();
                    string t2= st.top(); st.pop();
                 string ans = "(" + t2 + string(1, c) + t1 + ")";  //orrect order + string(1, c) here TC O(n1)+O(n2) bcz n1 1st string length..
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};