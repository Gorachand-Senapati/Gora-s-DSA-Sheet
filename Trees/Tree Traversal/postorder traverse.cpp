/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int>ans;
        postorderTraverse(root, ans);
        return ans;
    }
    void postorderTraverse(Node* node, vector<int>& ans){
        if(!node)return ;
        postorderTraverse(node->left,ans);
        postorderTraverse(node->right,ans);
        ans.push_back(node->data);
    }
};