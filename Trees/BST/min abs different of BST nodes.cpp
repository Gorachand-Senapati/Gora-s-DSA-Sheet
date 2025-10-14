class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* pre = nullptr;   // for Morris threading
        int prevVal = -1;          // store previous inorder value
        int minDiff = INT_MAX;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Visit current node
                if (prevVal != -1) {
                    minDiff = min(minDiff, abs(curr->val - prevVal));
                }
                prevVal = curr->val;
                curr = curr->right;
            } 
            else {
                // Find inorder predecessor
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    // Make thread
                    pre->right = curr;
                    curr = curr->left;
                } 
                else {
                    // Thread already exists, remove it
                    pre->right = nullptr;

                    // Visit current node
                    if (prevVal != -1) {
                        minDiff = min(minDiff, abs(curr->val - prevVal));
                    }
                    prevVal = curr->val;

                    curr = curr->right;
                }
            }
        }

        return minDiff;
    }
};