//Topo sort using Khan's Algorithm (BFS Approach)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>>adj;
        for(auto& edge:edges){
            int u= edge[0];
            int v=edge[1];
            adj[u].push_back(v);//dir so need only 1
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
        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0)q.push(it);//if agian any node indeg )
            }
        }
        return ans;
    }
};