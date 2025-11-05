class Solution {
 private: 
  bool dfsCycle(int node,unordered_map<int, vector<int>>&adj,
  int vis[], int pathVis[]){
      vis[node]=1;
      pathVis[node]=1;//make both vis
      for(auto it:adj[node]){
          if(!vis[it]){
             if(dfsCycle(it,adj,vis,pathVis) == true)return true;
          }else if(pathVis[it]==1){//if the node prev vis but it has vistited the same pathe
              return true;
          }
      }
      pathVis[node]=0;//if return false the no vis the path
      return false;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>>adj;//make a adj list
        for(auto& edge: edges){
            int u= edge[0];
            int v=edge[1];
            adj[u].push_back(v);//for directed graph only one time push
        }
        //make a vis and a pathvis array
        int vis[V]={0};
        int pathVis[V]={0};
        //check for connected commponent
        for(int i=0;i<V;i++){//if any one given cycle true
            if(dfsCycle(i,adj,vis,pathVis)== true)return true;
        }
        return false;
    }
};

//if use only one vis array so for vis make 1 and for path vis make 2 
class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1; // mark as 'in recursion path'

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis)) return true;
            }
            else if (vis[it] == 1) {
                // if neighbor is in current path -> cycle
                return true;
            }
        }

        vis[node] = 2; // mark as completely processed
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};