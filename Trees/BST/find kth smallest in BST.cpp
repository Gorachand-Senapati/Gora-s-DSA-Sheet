class Solution {
public:
   void inorder(TreeNode* root, int k, int &ksmall,int &counter){
    if(root == NULL) return;
     inorder(root->left,k, ksmall,counter);
     counter++;//after visit left subtree
     if(counter == k){
        ksmall= root->val;
        return;
     }
     inorder(root->right,k, ksmall, counter);
   }
    int kthSmallest(TreeNode* root, int k) {
        int kSmall = INT_MIN;
        int counter = 0;
        inorder(root,k, kSmall,counter);
        return kSmall;
    }
};
// if do by O(1) space then use morris inorder traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;
        int kSmallest = -1;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Visit the node
                count++;
                if (count == k)
                    kSmallest = curr->val;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pre = curr->left;
                while (pre->right != nullptr && pre->right != curr)
                    pre = pre->right;

                if (pre->right == nullptr) {
                    // Create a temporary thread
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // Remove the thread
                    pre->right = nullptr;
                    count++;
                    if (count == k)
                        kSmallest = curr->val;
                    curr = curr->right;
                }
            }
        }

        return kSmallest;
    }
};
