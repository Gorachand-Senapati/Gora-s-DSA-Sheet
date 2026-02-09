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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(auto & it :nums) trie.insert(it);
        int maxi =0;
        for(auto & it: nums){
            maxi = max(maxi,trie.getMax(it));//gibe the number which give max
        }
        return maxi;
    }
};