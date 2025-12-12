class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);//index 1 base
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});//und so both
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9), parent(n+1);//1 bse adn infin & parent array
        for(int i=1;i<=n;i++){
            parent[i]=i;//intial came from self
        }
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            int node =it.second;
            int dis=it.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNd = it.first;
                int wt =it.second;
                if(dis + wt < dist[adjNd]){
                    dist[adjNd]=dis+wt;
                    pq.push({dist[adjNd], adjNd});
                    parent[adjNd]=node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        
        vector<int>path;
        int node = n;//start from last
        //backtrack using parent array so O(n)extra Tc
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);//because while loop stop at 1
        //for gfg need the  final weight first
        path.push_back(dist[n]);//only this line extra add 
        reverse(path.begin(), path.end());
        return path;
        
    }
};