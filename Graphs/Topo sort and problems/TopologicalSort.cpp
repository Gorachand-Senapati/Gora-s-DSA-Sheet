class Solution {
private:
 void dfs(int node,unordered_map<int, vector<int>>&adj,int vis[],stack<int>&st){
     vis[node]=1;
     for(auto it:adj[node]){
         if(!vis[it]) dfs(it, adj, vis, st);
     }
     st.push(node);
 }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>>adj;
        for(auto& edge:edges){
            int u= edge[0];
            int v=edge[1];
            adj[u].push_back(v);//dir so need only 1
        }
        int vis[V]={0};
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj,vis,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};