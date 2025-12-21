// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;//src dist 0
        for(int i=0;i<V;i++){
            for(auto it: edges){
                int u= it[0];
                int v= it[1];
                int wt= it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v]= dist[u]+ wt;
                }
            }
        }
        //find for negaitve edge cycle
        for(auto it: edges){
                int u= it[0];
                int v= it[1];
                int wt= it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
        }
        return dist;
    }
};