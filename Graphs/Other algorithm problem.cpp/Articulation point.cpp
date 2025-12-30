// User function Template for C++

class Solution {
private:
 int timer = 1;//global timer start from here
 void dfs(int node, int parent,vector<vector<int>>adj,vector<int>&tin,
 vector<int>&low,vector<int>&vis,vector<int>&mark){
     vis[node]=1;
     tin[node]= low[node]=timer;
     timer++;
     int child = 0;
     for(auto it: adj[node]){
         if(it == parent)continue;//not need parent 
         if(!vis[it]){
             dfs(it,node,adj,tin,low,vis,mark);
             low[node] = min(low[it], low[node]);//whn not move 
             if(low[it] >= tin[node] && parent !=-1){//not starting and go before>= need 
                 mark[node]=1;//articulation point
             }
             child++;
         } else{//if visited then simple change low of node with tin[it]
             low[node] = min(tin[it], low[node]);//** main improtant 
         }
     }
     if(child > 1 && parent == -1){
         mark[node]=1;//if st point has more than 1 child
     }
 }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
       vector<int>vis(V,0);//visted array
       vector<int>tin(V);//time of insert when dfs
       vector<int>low(V);//lowest time to reach when parent != -1 and not visited
       vector<int>mark(V,0);//for articulation point
       //for not connected component check 
       for(int i=0;i<V;i++){
           if(!vis[i]){
               dfs(i,-1,adj,tin,low, vis, mark);
           }
       }
       vector<int>ans;
       for(int i=0;i<V;i++){
           if(mark[i] ==1){
               ans.push_back(i);
           }
       }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};