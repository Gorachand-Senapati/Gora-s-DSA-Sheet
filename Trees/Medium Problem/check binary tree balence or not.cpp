// BFA O(n2) time and O(h) space
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

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh= maxDepth(root->left);// l subtree
        int rh= maxDepth(root->right);//r subtree
        if(abs(lh-rh) > 1) return false;
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        if(!left || !right) return false;//if anyone give false
        return true;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;//base case
        int leftHt = maxDepth(root->left);
        int rightHt = maxDepth(root->right);
        return max(leftHt, rightHt) +1;
    }
};

// TC O(n) and SC O(h)
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

    bool isBalanced(TreeNode* root) {
       return maxDepth(root) !=-1;//if not return -1 then true ;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;//base case
        int leftHt = maxDepth(root->left);
        if (leftHt==-1) return -1;
        int rightHt = maxDepth(root->right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt)> 1) return -1;
        return max(leftHt, rightHt) +1;
    }
};