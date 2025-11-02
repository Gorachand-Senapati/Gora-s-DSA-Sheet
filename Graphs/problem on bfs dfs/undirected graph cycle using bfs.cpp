class Solution {
  public:
  
  bool detectCycle(unordered_map<int, vector<int>>&adj, int src,  vector<int>&vis ){
      vis[src]=1;
      queue<pair<int,int>>q;//value and parent
      q.push({src, -1});
      while(!q.empty()){
          int node = q.front().first;
          int par = q.front().second;
          q.pop();
          for(auto it:adj[node]){
              if(!vis[it]){
                  vis[it]=1;
                  q.push({it,node});
              } else if(par != it){//if visited and not parent 
                  return true;
              }
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
        for(int i=0;i<V;i++){//means if graph has connected components then no need to check all nodes
            if(!vis[i]){
               if (detectCycle(adj,i, vis) == true) return true;
            }
        }
        return false;
    }
};