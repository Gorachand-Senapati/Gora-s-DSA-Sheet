class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make a directed graph
        unordered_map<int, vector<int>> adj;
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // [2,1] means 2-> 1 (to take 1, must finish 0)
        }

        // now check for cycle using Kahn's algorithm (BFS Topological Sort)
        vector<int> inDeg(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDeg[it]++; // count indegree of each node
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i); // push all nodes with indegree 0
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) { // FIX: typo 'ndoe' → 'node'
                inDeg[it]--;
                if (inDeg[it] == 0) q.push(it);
            }
        }
        return ans.size() == numCourses; // if all courses done → no cycle return true or false
    }
};