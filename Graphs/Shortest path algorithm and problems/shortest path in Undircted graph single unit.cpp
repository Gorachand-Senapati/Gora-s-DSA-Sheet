class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        unordered_map<int, vector<int>>adj;
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);//undirected so both
        }
        //make a dist array
        vector<int>dist(V);
        for(int i=0;i<V;i++){dist[i]= 1e9 ;}//INT_MAX
        dist[src] = 0;
        //bfs
        queue<int>q;//where only store nodes
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it]= dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(V,-1);//ans array
        for(int i=0;i<V;i++){
            if(dist[i] != 1e9){
                ans[i]=dist[i];//means only 1e9 dist is -1
            }
        }
        return ans;
    }
};