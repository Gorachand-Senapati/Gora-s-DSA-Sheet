//921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n =s.size();
        stack<int>st;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(st.empty())cnt++;
                else st.pop();
            }
        }
        if(!st.empty() && cnt !=0) return st.size()+cnt;
        if(!st.empty()) return st.size();
        else return cnt;
    }
};