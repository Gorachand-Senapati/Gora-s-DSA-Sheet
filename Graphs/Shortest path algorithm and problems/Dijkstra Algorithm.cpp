class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        int E = edges.size();
        unordered_map<int,vector<pair<int,int>>>adj;//make adj list pair with wt
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            //for undirected graph make 2
        }
        //make min heap pq where always min dist in top so pop first
        // T = pair<int,int>
// Container = vector<T>
// Comparator = greater<T>
/*priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;*/
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        dist[src] =0;//self so 0
        pq.push({0,src});//dist,node
        
        while(!pq.empty()){ //total V times
            int dis = pq.top().first;//this need log (heap size) for top
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){//for adj pair = it .. also E times go edges so TC = E log V
                int v= it.first;//adj node
                int wt = it.second;
                if (dis > dist[node]) continue;//Without this, your code may run slower or push many useless items in PQ.
                if(dis + wt < dist[v]){
                    dist[v]= dis+wt;
                    pq.push({dist[v],v});//dist, adjnode
                }
            }
        }
        return dist;
    }
};

//using set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        int E = edges.size();
        unordered_map<int,vector<pair<int,int>>>adj;//make adj list pair with wt
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            //for undirected graph make 2
        }
        //make set accending order store in top
        set<pair<int,int>>st;
        
        vector<int>dist(V,1e9);
        dist[src] =0;//self so 0
        st.insert({0,src});//dist,node
        
        while(!st.empty()){
            auto it =*(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it:adj[node]){//for adj pair = it
                int v= it.first;//adj node
                int wt = it.second;
                if (dis > dist[node]) continue;//Without this, your code may run slower or push many useless items in PQ.
                if(dis + wt < dist[v]){
                    //erase if it existed
                    if(dist[v] != 1e9){
                        st.erase({dist[v],v});
                    }
                    dist[v]= dis+wt;
                    st.insert({dist[v],v});//dist, adjnode
                }
            }
        }
        return dist;
    }
};

/*  Why logarithmic time complexity?
In Dijkstra's algorithm, we often use a priority queue (min-heap) to efficiently
O( V* ( pop vertex from minheap + no. of edges on each vertex * push into pq) ) 
 O( V* ( log(heap size) + ne*log(heap size) )
O( V* ( log(heap size) * ( ne + 1) )
ne = V-1 in a dense graph where every node has edge to the rest of the nodes.
O( V* ( log(heap size) * ( V )
O( V^2 * ( log( heap size ) )
heap size = (V-1)^2 = V^2 when every one node is pushing other V-1 node.
O( V^2 * ( log(V^2) )
total degree = 2*E(number of edges) 
at worst case total degree =  V*(V-1) = V^2 = 2*E when every node has edge to the rest of nodes.
=>  O(2*E*2*log(V) ) => O( E*log(V) )
*/