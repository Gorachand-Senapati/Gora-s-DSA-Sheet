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
    int removeStones(vector<vector<int>>& stones) {
        //first find the grid size
        int n = stones.size();
        int maxRow =0, maxCol =0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol +1);//for safety need extra 1 size
        unordered_map<int,int>stoneNodes;//in map store where the stone nodes
        for(auto it: stones){
            //rows- node in disjoint set
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow+1;//col start from whre row numbering fininsh
            ds.unionbySize(nodeRow, nodeCol);//make connected
            stoneNodes[nodeRow] =1;//in map mark it there is stone
            stoneNodes[nodeCol] =1;//in map mark it there is stone
        }
        //now check how much component have
        int cntC=0;
        for(auto it:stoneNodes){
            if(ds.findultimateParent(it.first) == it.first) cntC++;//means parent itself means boss
        }
        return n- cntC;
    }
};//TC:O(N*alpha(N)) SC:O(N)