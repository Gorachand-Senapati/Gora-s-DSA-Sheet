class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int>vis(V,0);//1st all are not visited
        vis[0]=1;//make it visited
        queue<int>q;
        q.push(0);
        vector<int>bfs;//store ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            //now check who your neighbours
            for(auto it: adj[node]){//traverse node neighbour
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};//sc = O(3n) tc= O(n + 2e) because n for queue traverse and 2e for adjacency list traversal as degree of each node is counted in adjacency list.