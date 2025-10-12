class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
         while(root != NULL){
             if(root->data == x){
                 ceil= root->data;
                 return ceil;
             }
             if(x > root->data){
                 root= root->right;
             } else{
                 ceil = root->data;
                 root= root->left;
             }
         }
         return ceil;
    }
};

//find floor in BST
class Solution {
  public:
    int findFloor(Node* root, int x) {
        // code here
        int floor=-1;
         while(root != NULL){
             if(root->data == x){
                 floor= root->data;
                 return floor;
             }
             if(x < root->data){
                 root= root->left;
             } else{
                 floor = root->data;
                 root= root->right;
             }
         }
         return floor;
    }
};