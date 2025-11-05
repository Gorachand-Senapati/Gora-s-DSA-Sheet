class Solution {

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        int inDeg[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inDeg[it]++;//all node give the indegree how much node enter
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0)q.push(i);//its has no in degree
        }
    int cnt =0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0)q.push(it);//if agian any node indeg )
            }
        }
        if (cnt == V)return false;//if not make topo sort
        return true;
    }
};