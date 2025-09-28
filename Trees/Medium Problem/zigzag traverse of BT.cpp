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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>result;//result store array where store result is also array
       if(root == NULL) return result;
       queue<TreeNode*>q;
       q.push(root);
       bool flag= true;//if t= l to r and if f= r to l
       while(!q.empty()){//same as level order traverse
        int size= q.size();
        vector<int>row(size);//for single ans
        for(int i=0;i<size;i++){
            TreeNode* node =q.front();
            q.pop();
            //find position of fills node value
            int idx = flag ? i: (size-1-i);//if flag true so as it is if not then reverse order 
            row[idx]= node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        //after this level
        flag= !flag;
        result.push_back(row);
       }
       return result;
    }
};