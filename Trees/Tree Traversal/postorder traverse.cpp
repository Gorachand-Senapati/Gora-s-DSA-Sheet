/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int>ans;
        postorderTraverse(root, ans);
        return ans;
    }
    void postorderTraverse(Node* node, vector<int>& ans){
        if(!node)return ;
        postorderTraverse(node->left,ans);
        postorderTraverse(node->right,ans);
        ans.push_back(node->data);
    }
};

//Itrative traversal using 2 stack O(n) time and O(n) space
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        stack<Node*> s1, s2;
        vector<int> ans;
        s1.push(root);
        while(!s1.empty()){
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left != NULL) s1.push(node->left);
            if(node->right != NULL) s1.push(node->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->data);
            s2.pop();
        }
        return ans;
    }
};

//using single stack O(n) time and O(n) space
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* curr= root; TreeNode* temp;
        while(curr != NULL || !st.empty()){
            if(curr !=NULL){
                st.push(curr);
                curr= curr->left;
            } else{
                temp= st.top()->right;
                if(temp == NULL){
                  temp =st.top();
                  st.pop();
                  ans.push_back(temp->val);
                  while(!st.empty() && temp == st.top()->right){
                    temp= st.top();
                    st.pop();
                      ans.push_back(temp->val);
                  }
                } else{
                    curr= temp;
                }
            }
        }
        return ans;
    }
};
