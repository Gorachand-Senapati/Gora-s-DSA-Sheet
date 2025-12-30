class Solution {
private:
    int timer = 1;

    bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& tin, vector<int>& low,
             int c, int d) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                if (dfs(it, node, adj, vis, tin, low, c, d))
                    return true;

                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    if ((node == c && it == d) || (node == d && it == c))
                        return true;
                }
            } 
            else {
                // correct back edge update
                low[node] = min(low[node], low[it]);
            }
        }
        return false;
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        vector<vector<int>> adj(V);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(V, 0), tin(V), low(V);

        // handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis, tin, low, c, d))
                    return true;
            }
        }
        return false;
    }
};
