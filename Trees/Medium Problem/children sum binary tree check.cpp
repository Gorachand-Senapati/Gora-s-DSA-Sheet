
class Solution {
  public:
    int isSumProperty(Node *root) {
        // Base case: if the node is null or a leaf
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 1;
        
        int left_data = 0, right_data = 0;
        
        // If left child exists, get its data
        if (root->left)
            left_data = root->left->data;
        
        // If right child exists, get its data
        if (root->right)
            right_data = root->right->data;
        
        // Check the current node and recursively check subtrees
        if (root->data == left_data + right_data &&
            isSumProperty(root->left) &&
            isSumProperty(root->right))
            return 1;
        
        return 0;
    }
};

// 2236. Root Equals Sum of Children
class Solution {
public:
    bool checkTree(TreeNode* root) {
                if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL){
            return true;//if have no left right node
        }
        if(root->val == root->left->val + root->right->val){
            return true;
        }
        return false; 
    }
};