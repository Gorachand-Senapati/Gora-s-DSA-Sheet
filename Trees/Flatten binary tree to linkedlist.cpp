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
   TreeNode* nextRight;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};
//using stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr= s.top();
            s.pop();
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
            if(!s.empty()){
                curr->right= s.top();
                curr->left= NULL;
            }
        }
       
    }
};

//Morris Traversal O(n )time and O(1) space)

class Solution {
  public:
    void flatten(Node *root) {
        if (root == NULL)return ;
        Node* curr= root;
        //thread make
        while(curr != NULL){
            if(curr->left != NULL){
                Node* prev= curr->left;
                while(prev->right){
                    prev= prev->right;

                }
                prev->right = curr->right;
               curr->right= curr->left;
               curr->left = NULL;
            }
            curr= curr->right;
        }
        
    }
};