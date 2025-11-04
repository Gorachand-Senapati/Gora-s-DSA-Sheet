class Solution {
private:
   bool dfs(int node, int col, vector<int>&vis, vector<vector<int>>& graph){
    vis[node]= col;//make vis
    for(auto it:graph[node]){
        if(vis[it]==-1){
          if ( dfs(it, !col,vis,graph)== false) return false;//!col 0 to 1 1 to 0
        }
         else if(vis[it]== col) return false;
    }
    return true;
   }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();//need for make vis array
        vector<int>vis(V,-1);//make a vis array and -1 assign all for color need 0 and 1 of vis
        //check for connected comp
        for(int i=0;i<V;i++){
            if(vis[i]==-1){//not visited so do dfs
            //node, color, visted, graph
              if (dfs(i,0,vis,graph) == false) return false;
            }
        }
        return true;
    }
};

//using bfs
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, -1);//make a vis array 

        for (int start = 0; start < V; start++) {
            if (vis[start] == -1) {
                queue<int> q;
                q.push(start);
                vis[start] = 0;//give a 1st col

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : adj[node]) {
                        if (vis[it] == -1) {
                            q.push(it);
                            vis[it] = !vis[node];
                        } else if (vis[it] == vis[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};