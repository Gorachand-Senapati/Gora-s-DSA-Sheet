class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; // use stack to build smallest number
        // process each digit
        for (int i = 0; i < num.size(); i++) {
            // pop bigger digits from stack if we can still remove
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]); // push current digit
        }
        // if still have k left, remove from end (because number is increasing like 123456)
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        // build result from stack (this will be reverse order)
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        // remove leading zeros → since res is reversed, zeros are at the back
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        // reverse back to correct order
        reverse(res.begin(), res.end());
        // if empty after removing, return "0"
        return res.empty() ? "0" : res;
    }
};
