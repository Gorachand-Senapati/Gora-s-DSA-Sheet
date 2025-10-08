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
    // Step 1: Mark all parent nodes and also find the node where infection starts
    TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode = NULL;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start)
                startNode = curr; // found starting node

            if (curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return startNode;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // child -> parent
        TreeNode* startNode = markParent(root, parent_track, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        int time = -1; // start from -1 because the first level doesn’t take time yet

        while (!q.empty()) {
            int size = q.size();
            time++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // check left
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // check right
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // check parent
                if (parent_track[curr] && !visited[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }
        return time;
    }
};
