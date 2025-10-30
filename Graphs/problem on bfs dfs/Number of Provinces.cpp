class Solution {
public:
   void dfs(vector<vector<int>>& adj,int node, vector<int>&vis){
    vis[node]= 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(adj,it,vis);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        //it given adjanceny matrix I need adj list so make it from the matrix;
        vector<vector<int>>adj(V);//adjLs vector of vector
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1 && i!=j){//if connected and no self loop
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(V,0);//make vis array
        int cnt= 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return cnt;
    }
};