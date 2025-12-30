class Solution {
private:
//Tarjan's Algorithm to find bridges in a graph
int timer =1;//give 0 or 1
void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<int>&tin,
         vector<int>&low, vector<vector<int>>&bridges){
            vis[node]=1;
            tin[node] = low[node] = timer;//1st time of insert and low est time to reach is timer
            timer++;
            for(auto it:adj[node]){
                if(it == parent) continue;//if parent
                if(!vis[it]){//if not visited
                    dfs(it,node, adj,vis,tin,low,bridges);
                    low[node]= min(low[node], low[it]);//updated current node when need to backtrack here both need low[it]
                    if(low[it] > tin[node]){//have bridge or not if low[it]<=tin[node] then not bridge
                        bridges.push_back({it,node});
                    }
                } else{//when visited
                    low[node]= min(low[node], low[it]);//updated current node when need to backtrack here also use tin[it] or low[it] both work 
                }
            }
         }
 
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //make the graph 
        vector<vector<int>>adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);//as undirected so from both side
        }
        vector<int>vis(n,0);
        vector<int>tin(n),low(n);//make 2 array tin= dfs time of insertion, 
             //low = min time to reach apart from parent
        vector<vector<int>>bridges;//store the ans
        //assuming graph is connected
        dfs(0,-1,adj, vis,tin,low,bridges);//0 - currnode, -1 parent
        return bridges;
    }
};