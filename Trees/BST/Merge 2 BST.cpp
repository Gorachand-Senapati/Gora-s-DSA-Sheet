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
  void inorder(TreeNode*root,vector<int>&arr){
    if(root == NULL) return ;
    if(root->left){
        inorder(root->left, arr);
    }
    arr.push_back(root->val);
    if(root->right){
        inorder(root->right,arr);
    }
  }
   
   TreeNode* buildBST(vector<int> temp,int st, int end){
    if(st > end) return NULL;
    int mid= st + (end-st)/2;
    TreeNode* root= new TreeNode(temp[mid]);
    root->left= buildBST(temp,st,mid-1);
    root->right= buildBST(temp, mid+1, end);
    return root;
   }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1,arr2;
        inorder(root1, arr1);inorder(root2,arr2);
        vector<int>temp;//sorted array store here final bST
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] <arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            } else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        while(i<arr1.size()){
            temp.push_back(arr1[i]);
                i++;
        }
        while(j<arr2.size()){
            temp.push_back(arr2[j]);
                j++;
        }
       return  buildBST(temp,0,temp.size()-1);

    }
}; //TC= O(m+n) + O(m+n) + O(m+n)= O(m+n) , SC= O(m+n) for array + O(h1+h2) for recursion stack

//Merge only 2 Trees
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};