class Solution {
    class DisjointSet{
    //vector<int>rank, parent, size;
public:
 vector<int>rank, parent, size;
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);//all initialize a single component
        int cntExtra = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findultimateParent(u) == ds.findultimateParent(v)){
                cntExtra++;
            } else{
                ds.unionbySize(u,v);//connect the component
            }
        }
        //find how much components
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.findultimateParent(i) ==i) cntC++;
        }
        int ans = cntC-1;//always ans would be total component -1
        if(cntExtra >= ans) return  ans;
        return -1;
    }
};