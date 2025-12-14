class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);//make adj list
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int cst = it[2];
            adj[u].push_back({v,cst});
        }

        queue<pair<int,pair<int,int>>>q;//{stops, {node, cost}}
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it .first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;//skip not need to grow
            for(auto iter:adj[node]){
                int v = iter.first;
                int edw = iter.second;
                if(cost + edw < dist[v] && stops <=k){
                    dist[v]= cost +edw;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];

    }
};