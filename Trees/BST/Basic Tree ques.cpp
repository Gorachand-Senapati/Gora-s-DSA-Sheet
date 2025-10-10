//find min value of a binary search tree
class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(root == NULL) return -1;
        while(root->left != NULL){
            root= root->left;
        }
        return root->data;
    }
};

//count leaves node
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if (root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

//count non leaves node
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        if (root == NULL) return 0;                        // empty tree
        if (root->left == NULL && root->right == NULL) return 0; // leaf node

        // current node is non-leaf: count 1 + counts from left and right
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};
