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
  
   bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL || q== NULL){
            return p == q;
        }
        bool isleftSame = isSameTree(p->left, q->left);
        bool isrightSame = isSameTree(p->right, q->right);
        return isleftSame && isrightSame && p->val == q->val;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == NULL || subroot == NULL){
            return root== subroot;//means both are null then true
        }
        if(root->val == subroot->val && isSameTree(root, subroot)){
            return true;//if both are same return true
        }
        return isSubtree(root->left , subroot)|| isSubtree(root->right, subroot);//if any one is true then return true
    }
};