class Solution {
  public:
    int priority(char c) {
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        // swap the brackets
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') { s[i] = ')'; }
            else if(s[i] == ')') { s[i] = '('; }
        }

        stack<char> st;
        string ans = "";

        for(int i = 0; i < n; i++) {
            char c = s[i];

            // Operand (letters or digits)
            if( (c >= 'A' && c <= 'Z') || 
                (c >= 'a' && c <= 'z') || 
                (c >= '0' && c <= '9') ) {
                ans += c;
            }
            // Opening parenthesis
            else if(c == '(') {
                st.push(c);
            }
            // Closing parenthesis
            else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // remove '('
            }
            // Operator
            else {
                if(c == '^') { // right associative not need ^ ^ in top
                    while(!st.empty() && priority(c) <= priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                } else { // left associative
                    while(!st.empty() && priority(c) < priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // reverse final answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
