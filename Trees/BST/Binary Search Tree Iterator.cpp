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
class BSTIterator {
    stack<TreeNode*>st;//for inorder traverse
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);//push upto extream left
    }
    
    int next() {
        TreeNode* temp= st.top();
        st.pop();
        pushAll(temp->right);//temp right all element push
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();//if stack not empty return true, if empty return false
    }
private:
  void pushAll(TreeNode* node){
    while(node != NULL){
        st.push(node);
        node= node->left;
    }
  }

};