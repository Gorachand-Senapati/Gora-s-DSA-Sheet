/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL;
        Node* suc= NULL;
        Node* curr = root;
        //find inorder prede same as floor
        while(curr != NULL){
            if(key <= curr->data){
                curr= curr->left;
            } else{
                pre= curr;
                curr= curr->right;
            }
        }
        curr= root;
         //find inorder succ same as ceil
        while(curr != NULL){
            if(key >= curr->data){
                curr= curr->right;
            } else{
                suc= curr;
                curr= curr->left;
            }
        }
        return {pre, suc};
    }
};