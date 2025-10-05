/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        if(root == NULL)return ans;
        queue<pair<Node* ,int>>q;//node->line
        q.push({root,0});
        map<int, int>mpp;//create a map line->node
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(mpp.find(line) == mpp.end()){//if not find line 
                mpp[line]= node->data;
            }
            if(node->left != NULL) q.push({node->left, line-1});//left decrease
            if(node->right != NULL) q.push({node->right, line+1});//right increase
        }
         for(auto it: mpp){// in map store in accending order
        ans.push_back(it.second);
    }
    return ans;
        
    }
   
};