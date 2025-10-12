class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder, i, INT_MAX);//i point every index and int_max is the maximum bound
    }
    TreeNode* build(vector<int>& preorder, int &i, int bound){
        if(preorder.size() == i ||preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);//index value is the root value or node
        root->left= build(preorder,i,root->val);//root is the upper bound for left
        root->right= build(preorder, i,bound);
        return root;
    }
};