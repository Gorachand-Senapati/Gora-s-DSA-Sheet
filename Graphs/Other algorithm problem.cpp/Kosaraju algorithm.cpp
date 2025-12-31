//Position this line where user code will be pasted.
class Solution {
 private:
  void dfs(int node,vector<vector<int>> &adj,vector<int>&vis,stack<int>&st){
      vis[node]= 1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,st);
          }
      }
      st.push(node);
  }
   void dfs2(int node,vector<vector<int>> &adjT,vector<int>&vis){
      vis[node]= 1;
      for(auto it:adjT[node]){
          if(!vis[it]){
              dfs2(it,adjT,vis);
          }
      }
  }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int>vis(V,0);
        //stack for know the starting point bcz strorgili connected 1 time dfs all visit
        stack<int>st;
        for(int i=0;i<V;i++){//step 1 for sort accoriding finish for find start
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<vector<int>> adjT(V);//transpose adj-reverse
        //step 2 reverse direction
        for(int i=0;i<V;i++){
            vis[i]=0;//make again unvisit
            for(auto it:adj[i]){
                //now connection i->it,so connect now it->i
                adjT[it].push_back(i);
            }
        }
        //do again dfs for reverse graph
        int ssc=0;//storngly connected component
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ssc++;//increase component
                dfs2(node,adjT,vis);
            }
        }
        return ssc;
    }
};//TC:O(V+E) SC:O(V+E)+O(V)+O(V) for adjT,vis,stack