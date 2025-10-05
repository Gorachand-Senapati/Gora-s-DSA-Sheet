/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
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
            mpp[line]= node->data;// add in map no need to check if line is present or not
            if(node->left != NULL) q.push({node->left, line-1});//left decrease
            if(node->right != NULL) q.push({node->right, line+1});//right increase
        }
         for(auto it: mpp){// in map store in accending order
        ans.push_back(it.second);
    }
    return ans;
    }
};