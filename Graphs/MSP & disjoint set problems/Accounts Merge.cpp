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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        //map mail with index if same then connect component
        unordered_map<string, int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    //if mail not find in index  then add it index g@com, b@.c0m =1 ..
                    mapMailNode[mail]=i;
                } else{
                    ds.unionbySize(i,mapMailNode[mail]);//if not then connect component
                }
            }
        }
        vector<vector<string>> mergeMail(n); //now need merge mail for same parent
        for(auto it: mapMailNode){
            string mail = it.first;
            int node =ds.findultimateParent(it.second);//check the parents if same connect it
            mergeMail[node].push_back(mail);//mail add with parent index
        }
        //connect with name 
        vector<vector<string>>ans;//store ans here
        for(int i=0;i<n;i++){
            if(mergeMail[i].size() == 0) continue;//if index empty then skip it
            sort(mergeMail[i].begin(), mergeMail[i].end());//sort accending order of mail
            vector<string>temp;
            temp.push_back(accounts[i][0]);//name push all index
            for(auto it: mergeMail[i]){//go every index of mergemail and push there mail with owner
             temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};