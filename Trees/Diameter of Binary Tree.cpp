/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//BFA O(n2) time and O(h) space
class Solution {
  public:
    int diameter(Node* root) {
        if (root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        int diaThroughRoot = lh + rh;
        int diaLeft = diameter(root->left);
        int diaRight = diameter(root->right);

        return max(diaThroughRoot, max(diaLeft, diaRight));
    }

    int maxDepth(Node* root) { // height function
        if (root == NULL) return 0;
        int leftHt = maxDepth(root->left);
        int rightHt = maxDepth(root->right);
        return max(leftHt, rightHt) + 1;
    }
};

//optimise 
class Solution {
  public:
  int ans=0;
     int maxDepth(Node* root) {//find height
        if(root == NULL) return 0;//base case
        int leftHt = maxDepth(root->left);
        int rightHt = maxDepth(root->right);
        ans= max(ans, leftHt +rightHt);//curr diamiter  calcualted
        return max(leftHt,rightHt)+1;
    }
        int diameter(Node* root) {
            maxDepth(root);
            return ans;
    }
};