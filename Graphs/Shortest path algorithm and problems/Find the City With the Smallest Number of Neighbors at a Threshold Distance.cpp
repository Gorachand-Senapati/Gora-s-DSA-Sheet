class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //using floyed warshall
        vector<vector<int>>dist(n, vector<int>(n,1e9));//create a matrix assin int max
        for(int i=0;i<n;i++){
            dist[i][i]=0;//self loop 
        }
        for(auto it: edges){
            dist[it[0]] [it[1]] = it[2];
            dist[it[1]] [it[0]] = it[2];//bidierectional so  both
        }
        //floyed warshall
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    dist[i][j]= min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        int cntCity = n;
        int cityNo= -1;//no city visited
        for(int city=0;city<n;city++){
            int cnt =0;
            for(int adCit =0; adCit<n;adCit++){
                if(dist[city][adCit] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<= cntCity){
                cntCity= cnt;
                cityNo= city;
            }
        }
        return cityNo;
    }
}; //using floyed warshall TC= O(n^3) SC= O(n^2)

//dijkstra approach
// User function Template for C++
class Solution {
  public:
   void dijkstra(int n,vector<vector<pair<int,int>>>&adj ,
   vector<int>&dist, int src ){
       priority_queue<pair<int,int>, vector<pair<int,int>>,
       greater<pair<int,int>>>pq;//for dijkstra need pq
       
       pq.push({0,src});//src to src dist 0
       fill(dist.begin(), dist.end(), 1e9);//fill the dist array with 1e9
       dist[src]=0;
       
       while(!pq.empty()){
           int dis = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           for(auto it: adj[node]){
               int v = it.first;
               int wt = it.second;
               if(dis +wt <  dist[v]){
                   dist[v]= dis+wt;
                   pq.push({dist[v], v});
               }
           }
       }
   }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>matrix(n,vector<int>(n,1e9));//create a matrix
        for(int i=0;i<n;i++) matrix[i][i]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: edges){
            int u = it[0];
            int v= it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});//for undirected
        }
        //check for all node are source apply dijkstra
        for(int i=0;i<n;i++){
            dijkstra(n, adj,matrix[i], i);//vertex, edges, adjlist, row,src
        }
        //find the city by iterating over matrix
         int cntCity = n;
        int cityNo= -1;//no city visited
        for(int city=0;city<n;city++){
            int cnt =0;
            for(int adCit =0; adCit<n;adCit++){
                if(matrix[city][adCit] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<= cntCity){
                cntCity= cnt;
                cityNo= city;
            }
        }
        return cityNo;
    }
};
//TC= O(n*(E + V)logV) SC= O(n^2)