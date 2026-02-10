//bfa- O(m*n)  give tle
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int>ans;
        for(int i =0;i<m;i++){
            int xi= queries[i][0];
            int mi = queries[i][1];
            int maxXor = -1;
            for(int j=0;j<n;j++){
                if(nums[j] <= mi){
                    maxXor = max(maxXor,(nums[j] ^xi));
                }
            }
            ans.push_back(maxXor);
        }
        return ans;
    }
};

//optimal using trie
struct Node {
    Node* links[2];//0, 1 == NULL
    bool containsKey (int bit){
        return (links[bit] != NULL);//if the bit set or not
    }
    Node* get(int bit){
        return links[bit];//go the reference
    }
    void put(int bit, Node * node){
        links[bit]= node;//insert refternce
    }
};
class Trie {
public: 
  Node* root;
    Trie(){//constructor
     root = new Node();
    }
public: 
  void insert(int num) {//32 bit number make to insert in trie
  //started insert and checking from left = 31 
   Node* node = root;
   for(int i=31;i>=0;i--){
    int bit = (num >>i) & 1;//if the ith ind set or not
    if(!node->containsKey(bit)){
        node->put(bit,new Node());//insert and go create ref
    }
    node = node->get(bit);
   }
  }

  int getMax(int num){
    Node* node = root;
    int maxNum =0;
    for(int i=31;i>=0;i--){
        int bit = (num >>i) & 1;//give the bit
        //need opposite of it
        if(node->containsKey(1-bit)){//if it contains the opposite 1-0 =1
            maxNum = maxNum | (1 << i);//make the bit as 1 add the opposite
            node = node->get(1-bit);
        }else{//1-1 =0
            node = node->get(bit);//go the refterence bit
        }
    }
    return maxNum;
  }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        //make online queries to offline queries
        vector<pair<int,pair<int,int>>>oQ;//offlineQueries
        int q = queries.size();
        for(int i=0;i<q;i++){
            oQ.push_back({queries[i][1],{ queries[i][0], i}});//ai,xi,index
        }
        sort(oQ.begin(), oQ.end());//sort terms of ai or mi
        vector<int>ans(q,0 );//size q initialise 0
        int ind =0;
        int n = nums.size();
        Trie trie;//trie object
        //O(q+n)
        for(int i=0;i<q;i++){
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;
            while(ind <n && nums[ind] <= ai){
                trie.insert(nums[ind]);
                ind++;
            }
            //if no element insert still standing 0
            if(ind ==0) ans[qInd]= -1;
            else ans[qInd] = trie.getMax(xi);
        }
        return ans;
    }
};