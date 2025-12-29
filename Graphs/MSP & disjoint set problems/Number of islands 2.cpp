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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);//create disjoint set object
        vector<vector<int>>vis(n, vector<int>(m,0));//make a visited matrix 0 initailly
        int cnt =0;vector<int>ans;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){//if already a island
                ans.push_back(cnt);
                continue;
            }
            //if not island 
            vis[row][col]=1;
            cnt++;
            //check 4 side for connection of islands
            int dr[4]= {-1,0,1,0};
            int dc[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr= row+dr[i], nc = col + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){//check boundray valid
                    if(vis[nr][nc]==1){
                        //for ds need no of single row cnt start from 0 to n*m-1;
                        int nodeNo = row * m + col;
                        int adjndNo = nr * m+ nc;
                        //if ultimate parent not same then connect
                        if(ds.findultimateParent (nodeNo) != ds.findultimateParent (adjndNo)){
                            ds.unionbySize(nodeNo,adjndNo);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
//TC: O(k * alpha(n*m))  SC: O(n*m) + O(n*m) for disjoint set +O(n*m) for visited matrix