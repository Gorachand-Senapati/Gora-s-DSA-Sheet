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
class Solution {
public:
//if we use height and diam function so our time complixity = O(n^2) so change in height function for O(n);
  
  int ans =0;;
  int height(TreeNode* root){
    if(root== NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    ans = max(leftHt + rightHt, ans); //here currdiameter calculated

    return max(leftHt, rightHt)+1;
  }

    int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL){
    //         return 0;
    //     }

    //    int leftDiam = diameterOfBinaryTree(root->left);
    //    int rightDiam = diameterOfBinaryTree(root->right);

    //    int currDiam = height(root->left) + height(root->right);

    //     return max(currDiam, max(leftDiam, rightDiam));

    height(root);
    return ans;
    }
};