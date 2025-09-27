/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        inorderTraverse(root, ans);
        return ans;
    }
    void inorderTraverse(Node* node, vector<int>&ans){
        if(!node)return ;
        inorderTraverse(node->left, ans);
        ans.push_back(node->data);
        inorderTraverse(node->right, ans);
    }
};

//Itrative traverse O(n) time and O(n) space
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        stack<Node*>s;
        vector<int>ans;
        Node* node= root;
        while(true){
            if(node!= NULL){
                s.push(node);
                node = node->left;
            } else {
                if(s.empty() == true){
                    break;
                }
                node = s.top();
                s.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};