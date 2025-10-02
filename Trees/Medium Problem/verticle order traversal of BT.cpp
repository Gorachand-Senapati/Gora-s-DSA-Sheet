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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //create a map for node ,verticle, level. multisets use (if same number)
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int, int>>>todo;//push queue with 3 pair
        todo.push({root, {0,0}});//1st push root which veticle 0 llevel 0

        while(!todo.empty()){
            auto p= todo.front();//store
            todo.pop();//delete from q
            TreeNode* node = p.first;
            int x = p.second.first, y= p.second.second;//x = | verticle y= level __
            nodes[x][y].insert(node->val);
            if(node -> left) {
                todo.push({node->left, {x-1, y+1}});//here verticle decrease but level increase
            }
            if(node -> right) {
                todo.push({node->right, {x+1, y+1}});//here verticle level both are  increase
            }
        }
        vector<vector<int>>ans;//store ans
        for(auto p: nodes){//traverse all value of nodes map
            vector<int>col;//verticle 
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(),q.second.end());//every level of verticle insert in col
            }
            ans.push_back(col);
        }
        return ans;
    }
};