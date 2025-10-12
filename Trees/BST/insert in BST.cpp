class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root== NULL) return new TreeNode(val);//if no node in tree
        TreeNode* curr= root;
        TreeNode* newNode= new TreeNode(val);
        TreeNode* parent = NULL;
        while(curr != NULL){
            parent = curr;//before going curr null I store the parent for not loss
            if(curr->val > val){
                curr= curr->left;
            } else{
                curr= curr->right;
            }
        }
        if(parent->val > val){
            parent->left = newNode;
        } else{
            parent->right = newNode;
        }
        return root;
    }
};

class Solution {
  public:
    Node* insert(Node* root, int key) {
        if (root == NULL) return new Node(key);

        Node* curr = root;
        while (true) {
            if (key < curr->data) {
                if (curr->left != NULL) {
                    curr = curr->left;
                } else {
                    curr->left = new Node(key);
                    break;
                }
            } else if (key > curr->data) {
                if (curr->right != NULL) {
                    curr = curr->right;
                } else {
                    curr->right = new Node(key);
                    break;
                }
            } else {
                // If duplicates are not allowed, just break
                break;
            }
        }
        return root;
    }
};