class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
       vector<vector<int>> graphRev(V);// making a reverse adjcency list
        vector<int>inDeg(V,0);
        //put rev adjlist and indegree of the adjacency
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                graphRev[it].push_back(i);
                inDeg[i]++;//increment indeg
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0)q.push(i);
        }
        //for safe state
        vector<int>safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it:graphRev[node]){
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};
//cycle detection in directed graph using dfs
class Solution {
 private:
    bool dfs(int node, unordered_map<int,vector<int>>&adj,vector<int>&vis,
    vector<int>&pathVis, vector<int>&safeNode){
        vis[node]=1;
        pathVis[node]=1;
        safeNode[node]=0;//assume not safe
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,safeNode)){
                    return true;//if any node give true return true 
                }
            } else if(pathVis[it] == 1){//if vis and also pathvis
                return true;//cycle detected
            }
        }
        safeNode[node]=1;//mark safe
        pathVis[node]=0;//backtrack
        return false;
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v= edge[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0), pathVis(V,0), safeNode(V,0);
        vector<int>ans;//store the result
        //check all component
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathVis,safeNode);
            }
        }
        //if check ==1 then it safe node
        for(int i=0;i<V;i++){
            if(safeNode[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};