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
        //create a map for verticle(col), level(row). multiple nodes need sorted so multisets use (if same number)
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int, int>>>todo;//push queue with node, verticle and level pair all pair
        todo.push({root, {0,0}});//1st push root which veticle 0 llevel 0
//level order traversal
        while(!todo.empty()){
            auto p= todo.front();//store
            todo.pop();//delete from q
            TreeNode* node = p.first;//take the node
            int x = p.second.first, y= p.second.second;//x = | verticle y= level __
            nodes[x][y].insert(node->val);//add in map v, l, n
            if(node -> left) {
                todo.push({node->left, {x-1, y+1}});//here verticle decrease but level increase
            }
            if(node -> right) {
                todo.push({node->right, {x+1, y+1}});//here verticle level both are  increase
            }
        }
        //after finish traverse the nodes map do level order traversal
        vector<vector<int>>ans;//store ans
        for(auto p: nodes){//traverse all value of nodes map vertical wise
            vector<int>col;//vertical store
            for(auto q : p.second) {
                //for vertical every level insert
                col.insert(col.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(col);//now the vertical array push in ans
        }
        return ans;
    }
};