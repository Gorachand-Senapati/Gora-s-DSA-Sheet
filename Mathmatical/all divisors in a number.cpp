class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                if (n / i != i) { // avoid duplicate
                    ans.push_back(n / i);
                }
            }
        }
//if need accending order sorting  answer
        sort(ans.begin(), ans.end());

        for (int x : ans) {
            cout << x << " ";  // ✅ GFG expects direct printing
        }
    }
};
