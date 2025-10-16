class NodeValue {
public:
    int minNode;
    int maxNode;
    int maxSize; // Size of largest BST in this subtree

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtree(Node* root) { //we use NodeValue, which can carry multiple values at once.
        // Base case: An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Recurse for left and right subtrees (postorder)
        auto left = largestBSTSubtree(root->left);
        auto right = largestBSTSubtree(root->right);

        // Check if current node forms a valid BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            // It's a BST: compute new min, max, and size
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not a BST: return invalid range so parent can’t include it
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Return size of the largest BST subtree
    int largestBst(Node* root) {
        return largestBSTSubtree(root).maxSize;
    }
};



//Max Sum in BST in a Binary Tree LC-1373
 class NodeValue {
public:
    int minNode;
    int maxNode;
    int maxSum; // Size of largest BST in this subtree

    NodeValue(int minNode, int maxNode, int maxSum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
private:
        int ans =0;//global ans 
    NodeValue largestBSTSubtree(TreeNode* root) { 
 //we use NodeValue, which can carry multiple values at once. // Base case: An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Recurse for left and right subtrees (postorder)
        auto left = largestBSTSubtree(root->left);
        auto right = largestBSTSubtree(root->right);

        // Check if current node forms a valid BST
        if (left.maxNode < root->val && root->val < right.minNode) {
           int currSum = left.maxSum + right.maxSum + root->val;
           ans = max(ans, currSum);
            return NodeValue(
                min(root->val, left.minNode),max(root->val, right.maxNode), currSum);
        }

        // Not a BST: return invalid range so parent can’t include it
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
     ans =0;
      largestBSTSubtree(root);  
      return ans;
    }
};