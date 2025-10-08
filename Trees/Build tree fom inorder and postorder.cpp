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
   TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &postIdx, int left, int right){
    if(left>right) return NULL;
    TreeNode* root= new TreeNode(postorder[postIdx]);
    int inIdx= search(inorder,left,right, postorder[postIdx]);
    postIdx--;
     root->right = helper(inorder,postorder,postIdx,inIdx+1,right);
      root->left = helper(inorder,postorder,postIdx,left,inIdx-1);
        

        return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx= postorder.size()-1;
         return helper(inorder, postorder,postIdx,0, inorder.size()-1);
    }
};//O(n2)

class Solution {
  public:
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMp;
        for (int i = 0; i < inorder.size(); i++) {
            inMp[inorder[i]] = i; // value → index
        }

        return buildfullTree(postorder, 0, postorder.size() - 1,
                             inorder, 0, inorder.size() - 1, inMp);
    }

    Node* buildfullTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inMp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        Node* root = new Node(postorder[postEnd]);  // ✅ last element = root
        int inRoot = inMp[root->data];
        int numsLeft = inRoot - inStart;            // nodes in left subtree
        int numsRight = inEnd - inRoot;             // nodes in right subtree

        // Build subtrees — notice right subtree uses postEnd - 1 first Root → Right → Left
        root->right = buildfullTree(postorder, postEnd - numsRight, postEnd - 1,
                                    inorder, inRoot + 1, inEnd, inMp);

        root->left = buildfullTree(postorder, postStart, postEnd - numsRight - 1,
                                   inorder, inStart, inRoot - 1, inMp);

        return root;
    }
};//O(n)


