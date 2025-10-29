class Solution {
 private:
   void dfsTraverse(vector<vector<int>>& adj, int node,vector<int>&vis, vector<int>&ans ){
       vis[node]= 1;
      ans.push_back(node);
       //traverse all the neighbours
       for(auto it: adj[node]){
           if(!vis[it]){
               dfsTraverse(adj,it,vis, ans);
           }
       }
   }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,0);//make a visted vector all are now 0
        int start = 0;
        vector<int>ans;//store ans 
        dfsTraverse(adj, start,vis,ans);
        return ans;
    }
};