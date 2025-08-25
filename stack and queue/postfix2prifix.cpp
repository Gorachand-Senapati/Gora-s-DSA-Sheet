// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n= post_exp.size(), i=0;
        stack<string>st;
        while(i<n){
            char c =post_exp[i];
            if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                st.push(string(1,c));
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string ans = string(1,c) + t2 + t1;
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};