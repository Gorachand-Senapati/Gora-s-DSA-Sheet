class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();

        // Step 1: make jobs array {profit, deadline}
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Step 2: sort by profit (descending)
        sort(jobs.rbegin(), jobs.rend());

        // Step 3: find maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].second);
        }

        // Step 4: slot array (-1 = free)
        vector<int> slot(maxDeadline + 1, -1);

        int totalProfit = 0, cnt = 0;

        // Step 5: assign jobs greedily
        for (int i = 0; i < n; i++) {
            int d = jobs[i].second;
            for (int j = d; j > 0; j--) { // check from deadline backward
                if (slot[j] == -1) {
                    slot[j] = i; // assign job index
                    cnt++;
                    totalProfit += jobs[i].first; // add profit
                    break;
                }
            }
        }

        return {cnt, totalProfit};
    }
}; // tC= O(nlogn + n*maxDeadline) sC= O(n + maxDeadline)