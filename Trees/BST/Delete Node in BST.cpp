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

   TreeNode* getInorderSuccessor(TreeNode* root){//left most node in right subtree
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
   }
    TreeNode* deleteNode(TreeNode* root, int key) {//key is the value which to delete
    if(root == NULL){
        return NULL;
    }
        if(key >root->val){
          root->right = deleteNode(root->right, key);
        } else if(key < root->val){
           root->left = deleteNode(root->left, key);
        } else{
            //delete here root == key
            //1) If parent have 0 or 1 child so combine both
            if(root->left == NULL){
                TreeNode* temp = root-> right;
                delete root;
                return temp;
            } else if(root->right == NULL){
                TreeNode* temp = root-> left;
                delete root;
                return temp;
            } else {//2 children 
               TreeNode* IS = getInorderSuccessor(root->right);
               root->val = IS->val;
               root->right = deleteNode(root->right, IS->val);

            }
        }

        return root;
    }
};

//It also possible for Inorder predecessor which is right most node in left subtree
class Solution {
public:

   TreeNode* getInorderpredecessor(TreeNode* root){//right most node in left subtree
    while(root != NULL && root->right!= NULL){
        root = root->right;
    }
    return root;
   }
    TreeNode* deleteNode(TreeNode* root, int key) {//key is the value which to delete
    if(root == NULL){
        return NULL;
    }
        if(key >root->val){
          root->right = deleteNode(root->right, key);
        } else if(key < root->val){
           root->left = deleteNode(root->left, key);
        } else{
            //delete here root == key
            //1) If parent have 0 or 1 child so combine both
            if(root->left == NULL){
                TreeNode* temp = root-> right;
                delete root;
                return temp;
            } else if(root->right == NULL){
                TreeNode* temp = root-> left;
                delete root;
                return temp;
            } else {//2 children 
               TreeNode* IS = getInorderpredecessor(root->left);
               root->val = IS->val;
               root->left = deleteNode(root->left, IS->val);

            }
        }

        return root;
    }
};