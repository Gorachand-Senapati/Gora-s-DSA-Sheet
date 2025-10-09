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

 //Morris inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*curr = root;

        while(curr!= NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                 curr = curr->right;
            } else{
                //find inorder predecessor(IP)
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                };
                //logic
                if(IP->right == NULL){
                    //create Threade connection
                    IP->right = curr;
                    //for preorder traversal here add in ans the root then go left
                    curr = curr->left;
                } else {
                    //delete threade
                    IP->right = NULL;
                    ans.push_back(curr->val);//for preorder traversal remove this line and go right
                    curr= curr->right;
                }
            }
        }

        return ans;
    }
};