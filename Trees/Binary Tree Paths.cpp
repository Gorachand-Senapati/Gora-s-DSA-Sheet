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
  void allPaths(TreeNode* root, string path, vector<string>&ans){
    //base case
    if(root->left == NULL && root->right == NULL){
        ans.push_back(path);
        return;
    }
    if(root->left) {
        allPaths(root->left, path+"->" +to_string(root->left->val), ans);
    }

     if(root->right) {
        allPaths(root->right, path+"->" +to_string(root->right->val), ans);
    }
    
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = to_string(root->val);

        allPaths(root, path,ans);
        return ans;
    }
};

//if need array type path [ [5,3,2], [5,3,4], [5,8,7], [5,8,9] ]
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>path;
        allPaths(root, path, ans);
        return ans;
    }
    void allPaths(Node* root, vector<int>& path,  vector<vector<int>> &ans){
        if(root == NULL) return ;
        path.push_back(root->data);//curr node value store
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        } else{
            //recursivly call left and right subtree path
            allPaths(root->left, path, ans);
            allPaths(root->right, path, ans);
            
        }
        path.pop_back();//backtracking
    }
};