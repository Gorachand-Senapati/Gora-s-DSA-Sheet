class Solution {
  public:
  
  bool detectCycle(unordered_map<int, vector<int>>&adj, int node,  vector<int>&vis, int parent ){
      vis[node]=1;
      for(auto it: adj[node]){
          if(!vis[it]){
              if(detectCycle(adj, it,vis, node)== true)return true;
          } else if(it != parent){//visited but not parent ..so it visit by some other node ..cycle
              return true;
          }
      }
      //there no cycle
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // 1st work is make the edges in adj list
        unordered_map<int, vector<int>>adj;//make adj list
        for(auto &edge: edges){
            int u= edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);//make a visited array
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if (detectCycle(adj,i, vis,-1) == true) return true;
            }
        }
        return false;
    }
};