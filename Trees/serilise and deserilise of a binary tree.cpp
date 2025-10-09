/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s= "";
        queue<TreeNode*>q;//for level order traverse
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr== NULL){
                s.append("null,");//if no node
            } else{
                s.append(to_string(curr->val) + ',');
            }
            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //use string all operation so use sstream
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');//go upto when comma seen from start team it from oringinal string
        TreeNode* root= new TreeNode(stoi(str));//string to int str make
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            //for left connection
             getline(s,str,',');
             if(str=="null"){
                node->left = NULL;
             } else{
                TreeNode* leftNode= new TreeNode(stoi(str));//node left
                node->left = leftNode;
                q.push(node->left);
             }
            //for right connection
             getline(s,str,',');
             if(str=="null"){
                node->right = NULL;
             } else{
                TreeNode* rightNode= new TreeNode(stoi(str));//node left
                node->right = rightNode;
                q.push(node->right);
             }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));