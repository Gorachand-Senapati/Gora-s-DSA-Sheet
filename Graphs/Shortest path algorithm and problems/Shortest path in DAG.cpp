// User function Template for C++
class Solution {
private: 
  void topoSort(int node,unordered_map<int, vector<pair<int,int>>>&adj,
  vector<int>&vis, stack<int>&st){
      vis[node]=1;
      for(auto it: adj[node]){
          int v = it.first;//first value of pair is vertex
          if(!vis[v]){
              topoSort(v,adj,vis,st);
          }
      }
      st.push(node);
  }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int,int>>>adj;//make adj list with pair of wt
        for(int i=0;i<E;i++){//basis on edge not vertex
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});//directed so only 
        }
        //1. make a topo sort
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        //2. take a node out of the stack and relax update in dist array
        vector<int>dist(V,1e9);
        dist[0]=0;//which is souce
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node]+ wt < dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++){
            if(dist[i] != 1e9){
                ans[i]= dist[i];
            }
        }
        return ans;
    }
};
