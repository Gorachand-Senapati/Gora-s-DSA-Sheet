class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int node, vector<int>& vis, int &v, int &e) {
        vis[node] = 1;
        v++;                    // count this node
        e += adj[node].size();   // add all edges from this node
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, it, vis, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0;  // number of vertices in component
                int e = 0;  // sum of degrees in component
                dfs(adj, i, vis, v, e);
            // For a complete graph of v nodes:-    // each node connects to (v - 1) others => total edge appearances = v * (v - 1)
                if (e == v * (v - 1)) cnt++;
            }
        }
        return cnt;
    }
};