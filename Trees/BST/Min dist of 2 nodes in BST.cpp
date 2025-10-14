class Solution {
public:
   TreeNode* prev= NULL;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        int ans = INT_MAX;
        //left , root,right
        if(root->left){//left
            int leftMin = minDiffInBST(root->left);
            ans= min(ans,leftMin);
        }
        //root
        if(prev !=NULL){
            ans= min(ans,root->val -prev->val);
        }
        prev=root;//assign last visited value
         if(root->right){//right
            int rightMin = minDiffInBST(root->right);
            ans= min(ans,rightMin);
        }
        return ans;
    };
};