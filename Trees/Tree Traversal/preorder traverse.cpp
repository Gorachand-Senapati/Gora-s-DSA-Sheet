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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root, ans);
        return ans;
    }
private: //for I dont want to seet it public
  void preOrder(TreeNode* node, vector<int>& ans){
    if(node == NULL)return ;//base case when null point
    ans.push_back(node->val);//Root
    preOrder(node->left,ans);//left
    preOrder(node->right, ans);//right
  }//here not return any thing bcz change is refterence by ans
};

//using stack - iterative traversal
class Solution {
  public:
    vector<int> preorder(Node* root) {
        // code here
        stack<Node*>s;
        vector<int>ans;
        if(root == NULL)return ans;
        s.push(root);
        while(!s.empty()){
            root= s.top();
            s.pop();
            ans.push_back(root->data);
            if(root->right)s.push(root->right);
            if(root->left)s.push(root->left);
        }
        return ans;
    }
};