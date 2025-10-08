/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
    queue<TreeNode*>q;//level order  traverse 
    q.push(root);
    while(!q.empty()){
        TreeNode* curr= q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left]= curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right]= curr;
            q.push(curr->right);
        }
    }
 }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent_track;//node->parentnode for go upward
        markParent(root, parent_track, target);

        unordered_map<TreeNode* , bool>visited;//create a map visited or not
        queue<TreeNode*>que;//make for target level order traverse left, right , parent
        que.push(target);//1st target push
        visited[target]= true;
        int dist=0;
        while(!que.empty()){
            if(dist==k)break;
            dist++;
            int size = que.size();
           for(int i=0;i<size;i++){
             TreeNode* curr= que.front();
            que.pop();//after delete check  3 present or not
            if(curr->left && !visited[curr->left]){
                que.push(curr->left);
                visited[curr->left]= true;
            }
            if(curr->right && !visited[curr->right]){
                que.push(curr->right);
                visited[curr->right]= true;
            }
            if(parent_track[curr] && !visited[parent_track[curr]]){//if parent exist and not visited
                que.push(parent_track[curr]);
                visited[parent_track[curr]]= true;
            }
           }
        }
        vector<int>ans;
        while(!que.empty()){
            TreeNode* curr = que.front();que.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};