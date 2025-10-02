/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  bool isLeaf(Node* root){
      return (!root->left && !root->right);
  }

  // first add left boundary without leaves
  void addLeftBound(Node* root, vector<int>& res){
      Node* cur = root->left;
      while(cur){
          if(!isLeaf(cur)) res.push_back(cur->data);
          if(cur->left) cur = cur->left;
          else cur = cur->right;
      }
  }
  
  // add right boundary without leaves
  void addRightBound(Node* root, vector<int>& res){
      Node* cur = root->right;
      vector<int> temp;
      while(cur){
          if(!isLeaf(cur)) temp.push_back(cur->data);
          if(cur->right) cur = cur->right;
          else cur = cur->left;
      }
      // reverse order
      for(int i = temp.size()-1; i >= 0; i--){
          res.push_back(temp[i]);
      }
  }
  
  // add leaves nodes
  void addLeaves(Node* root, vector<int>& res){
      if(!root) return;
      if(isLeaf(root)){
          res.push_back(root->data);
          return;
      }
      if(root->left) addLeaves(root->left, res);
      if(root->right) addLeaves(root->right, res);
  }
  
  vector<int> boundaryTraversal(Node *root) {
      vector<int> res;
      if(!root) return res;
      if(!isLeaf(root)) res.push_back(root->data); // root included if not leaf
      
      addLeftBound(root, res);//first leftboundary without leaves
      addLeaves(root, res);//all leaves
      addRightBound(root, res);//right boundary without leaves
      
      return res;
  }
// TC= O(N)
// SC= O(H) for recursion stack, O(1) for others