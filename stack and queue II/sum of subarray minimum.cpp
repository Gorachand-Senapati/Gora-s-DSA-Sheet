class Solution {
public:
    int n;
    vector<int> nextSmaller, prevSmaller;

    void findNse(vector<int>& arr) {
        stack<int> st;
        int i = n - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
            i--;  // move left
        }
    }

    void findPse(vector<int>& arr) {
        stack<int> st;
        int i = 0;
        while (i < n) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
            i++;  // move right
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        
        // ✅ create vectors directly with size n
        nextSmaller = vector<int>(n, n);   // default = n
        prevSmaller = vector<int>(n, -1);  // default = -1

        findNse(arr);
        findPse(arr);

        long long total = 0;
        long long MOD = 1e9 + 7;

        int i = 0;
        while (i < n) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            total = (total + left * right % MOD * arr[i]) % MOD;i++;
             //So % MOD keeps the number within safe integer limits and matches the problem’s requirement.
            //Step by step:

// left * right → could be huge.

// (left * right) % MOD → reduce it immediately.
// Multiply by arr[i].
// → Again, might be huge, so ( (left * right % MOD) * arr[i] ) % MOD.
// Add it to total.
// → Again % MOD to stay safe and consistent.
            i++;
        }

        return (int)total;
    }
};
