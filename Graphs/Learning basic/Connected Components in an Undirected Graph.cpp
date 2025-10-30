class Solution {
 private:
  void dfs(int node, unordered_map<int, vector<int>>&adj,vector<int>&vis, vector<int>&ans){
      vis[node] = 1;
      ans.push_back(node);
      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it, adj,vis, ans);
          }
      }
  }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>>ans;//store the ans
       vector<int>vis(V, 0);//make a visited array
       unordered_map<int, vector<int>>adj;//make for adjacentlis nodes -{neighbour nodes}
        //make adjacencey list using edges //graph representation
        for(const auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);//since the graph is undirected
        }
        //iterate through all vertices and perform DFS on unvisited nodes
        for(int i=0;i< V; i++){//visited array size
            if(!vis[i]){
                vector<int>currentComponent;
                dfs(i, adj,vis,currentComponent);//dfs traverse
                ans.push_back(currentComponent);
            }
        }
        return ans;
    }
};
