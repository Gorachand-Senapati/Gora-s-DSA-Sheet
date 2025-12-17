class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);//1 index base
        for(auto it:times){
            int u = it[0];
            int v= it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            for(auto itr:adj[node]){
                int v = itr.first;
                int wt = itr.second;
                if(dis+wt < dist[v]){
                    dist[v]= dis+wt;
                    pq.push({dist[v],v});//updated dist, adj node
                }
            }
        }
        int ans = INT_MIN;//need max value of dist array
        for(int i=1;i<dist.size();i++){
            if(dist[i] == 1e9) return -1;
            ans= max(ans, dist[i]);
        }
        return ans;
    }
};