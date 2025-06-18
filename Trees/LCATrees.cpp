/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val || root->val == q->val){
            return root;//1st nijei nejer lca
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left,p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p, q);

        if(leftLCA && rightLCA){
            return root;//ans
        } else if(leftLCA != NULL){
            return leftLCA;
        } else{
            return rightLCA;
        }
    }
};