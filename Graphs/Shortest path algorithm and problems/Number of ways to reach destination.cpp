class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);//adj list 
        for(auto it: roads){
            int u = it[0];
            int v= it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long, int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>>pq;
        vector<long long>dist(n,1e18);
        dist[0]= 0;
        vector<int>ways(n,0);
        ways[0]= 1; // There's 1 way to reach the source (itself)
        const int mod = 1e9 + 7;
        pq.push({0,0});//dist,node
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;
            for(auto itr:adj[node]){
                int v = itr.first;
                long long wt = itr.second;
                if(dis + wt < dist[v]){
                    dist[v]= dis+wt;
                    pq.push({dist[v],v});
                     // Copy the number of ways to the new node
                     ways[v]= ways[node];
                } else if(dis +wt == dist[v]){
                    //update the ways 
                    ways[v]= (ways[v]+ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};