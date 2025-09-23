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
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        inorderTraverse(root, ans);
        return ans;
    }
    void inorderTraverse(Node* node, vector<int>&ans){
        if(!node)return ;
        inorderTraverse(node->left, ans);
        ans.push_back(node->data);
        inorderTraverse(node->right, ans);
    }
};