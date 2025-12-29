class DisjointSet{
    // vector<int>rank, parent, size;
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
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        //step1- 1st connected components make
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 0) continue;//skip it 
                int dr[4]= {-1,0,1,0};
                 int dc[4]={0,1,0,-1};
              for(int i=0;i<4;i++){
                int nr= r+dr[i], nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] ==1){
                    //make connected 
                    int nodeNo = r * n +c, adjNo= nr* n + nc;
                    ds.unionbySize(nodeNo,adjNo);//connect the components
                }
              }
            }
        }
        //step1- 1st connected components make
        int ans = 0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 1) continue;//skip it 
                set<int>components;//make a components set
                int dr[4]= {-1,0,1,0};
                 int dc[4]={0,1,0,-1};
              for(int i=0;i<4;i++){
                int nr= r+dr[i], nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n ){
                    if(grid[nr][nc] == 1){
                    components.insert(ds.findultimateParent(nr*n+nc));//store in set unique parstore
                    }
                }
              }

              int sizeTot = 0;
              for(auto it: components){
                sizeTot+= ds.size[it];
              }
              ans = max(ans, sizeTot+1);//check from size array and extra 1 add for 0 convert 1
            }
        }
        //now if all cell have 1
        for(int cell =0;cell<n*n;cell++){
            ans = max(ans, ds.size[ds.findultimateParent(cell)]);//check max size from size array
        }
        return ans;
    }
}; //TC = O(n*n * alpha(n*n)) SC: O(n*n) for disjoint set