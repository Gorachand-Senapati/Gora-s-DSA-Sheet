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
int search(vector<int>& inorder,int left,int right,int val){
  for(int i= left;i<=right;i++){
    if(inorder[i] == val){
        return i;
    }
  }
  return -1;
}

 TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if(left>right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        
        int inIdx = search(inorder, left,right,preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder,inorder,preIdx,left,inIdx-1);
        root->right = helper(preorder,inorder,preIdx,inIdx+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder,inorder,preIdx,0, inorder.size()-1);
    }
};//O(n2)

class Solution {
  public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++) {
            inMp[inorder[i]] = i; // ✅ map value → index
        }

        return buildfullTree(preorder, 0, preorder.size() - 1,
                             inorder, 0, inorder.size() - 1, inMp);
    }

    Node* buildfullTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inMp) { // ✅ pass by reference
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        Node* root = new Node(preorder[preStart]);
        int inRoot = inMp[root->data];
        int numsLeft = inRoot - inStart;

        root->left = buildfullTree(preorder, preStart + 1, preStart + numsLeft,
                                   inorder, inStart, inRoot - 1, inMp);
        root->right = buildfullTree(preorder, preStart + numsLeft + 1, preEnd,
                                    inorder, inRoot + 1, inEnd, inMp);
        return root;
    }
};//O(n) time and space
