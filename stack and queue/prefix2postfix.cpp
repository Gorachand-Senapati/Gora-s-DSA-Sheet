// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        int n= pre_exp.size(), i=n-1;
        stack<string>st;
        while(i>=0){
            char c =pre_exp[i];
            if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                st.push(string(1,c));
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string ans = t1+ t2 + string(1,c);
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};