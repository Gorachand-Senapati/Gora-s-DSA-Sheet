// Disjoint set class 
class DisjointSet{
    vector<int>rank, parent, size;
public:
  //constructor
  DisjointSet(int n) {
    //size defind for rank and parent which work 0 and 1 index base
    rank.resize(n+1, 0);//size n+1 assign 0
    parent.resize(n+1);
    size.resize(n+1,1);
    //parent itself
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
  }

  int findultimateParent(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node]= findultimateParent(parent[node]);//assign for path compressing for constant time if only function then log n time
  }

  //combine nodes 2 nodes and check height which is rank
  void unionbyRank(int u, int v){
    int ulp_u= findultimateParent(u);
    int ulp_v= findultimateParent(v);
    if(ulp_u == ulp_v) return; //if same component
    if(rank[ulp_u] < rank[ulp_v]){//if rank of u less than v
        parent[ulp_u]= ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){//if rank of v less than u
        parent[ulp_v]= ulp_u;
    }
    else{ //if both same rank
        parent[ulp_v]= ulp_u;
        rank[ulp_u]++;//vice versa also same 
  }
}
//check by size now
  void unionbySize(int u, int v){
    int ulp_u= findultimateParent(u);
    int ulp_v= findultimateParent(v);
    if(ulp_u == ulp_v) return; //if same component
    if(size[ulp_u] < size[ulp_v]){
        size[ulp_v]+= size[ulp_u];
        parent[ulp_u]= ulp_v;
    } else{
        size[ulp_u]+= size[ulp_v];
        parent[ulp_v]= ulp_u;
    }
}
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
       vector<pair<int, pair<int,int>>>newEdges;
       //O(V+E)
       for(auto it: edges){
           int u= it[0];
           int v= it[1];
           int w= it[2];
           newEdges.push_back({w,{u,v}});//no need to create 2 times its automatically work it
       }
       sort(newEdges.begin(), newEdges.end());//sort according wt O( v log E)
       DisjointSet ds(V);//pass in class
       int mstWt=0;
       //O(E * 4 alpha means constant *2) for 2 times use ds
       for(auto it: newEdges){
           int wt = it.first;
           int node = it.second.first;
           int adjNode = it.second.second;
           //if node and adjNOde are not same component then wt add in mstWT
           if(ds.findultimateParent(node) != ds.findultimateParent(adjNode)){
               mstWt+= wt;
               //unionbyrank or unionbysize update anything of two
               ds.unionbySize(node, adjNode);
           }
       }
       return mstWt;
    }
};