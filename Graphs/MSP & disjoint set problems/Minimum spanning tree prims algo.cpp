class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int, pair<int,int>>,
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>>pq;//{wt,{node,parent}}
        //it also possible only pair {wt,node} but for future if need tree then do this
        vector<int>vis(V,0);//visited array
        pq.push({0,{0,-1}});//starting parent null and wt null st from 0
        int sum =0;
        //apply prims algo TC:O(ElogE) SC:O(E)+O(V)
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            int w = itr.first;
            int node = itr.second.first;
            int parent = itr.second.second;
            if(vis[node] == 1) continue;//skip it if visited 
            vis[node]=1;
            sum+=w;
            for(auto it:adj[node]){
                if(!vis[it.first]){
                    int v = it.first;
                    int wt = it.second;
                    pq.push({wt,{v,node}});
                }
            }
        }
        return sum;
        
    }
};