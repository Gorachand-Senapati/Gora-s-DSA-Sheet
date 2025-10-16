class Solution {
public:
   void inorder(TreeNode* root, vector<int>&arr){
    if(root == NULL) return ;
    if(root->left) inorder(root->left, arr);
    arr.push_back(root->val);
    if(root->right) inorder(root->right, arr);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root, arr);
        int l=0, r= arr.size()-1;//sorted order two sum find
        while(l<r){
            if(arr[l] + arr[r] == k) return true;
            else if(arr[l]+ arr[r] > k){
                r--;
            } else{
                l++;
            }
            
        }
     return false;
    }
};
// O(1) space 

class BSTIterator {
    stack<TreeNode*>st;//for inorder traverse and create bfore()and next
    //reverse= true= before and reverse = false= next
    bool reverse= true;
    
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse= isReverse;
        pushAll(root);//push upto extream left
    }
    
    int next() {
        TreeNode* temp= st.top();
        st.pop();
       if(!reverse) pushAll(temp->right);//temp right all element push when need next
       else pushAll(temp->left);//when need before
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();//if stack not empty return true, if empty return false
    }
    private:
  void pushAll(TreeNode* node){
    while(node != NULL){
        st.push(node);
        if(reverse == true) node = node->right;//before decending order
        else  node= node->left;//next
    }
  }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        //make 2 different object
        BSTIterator l(root,false);//for next means accending order
        BSTIterator r(root,true);//for before means decending  order 
        int i = l.next();//for next start iterator
        int j = r.next();//for before start iterator
        while(i<j){
            if(i+j == k) return true;
            else if( i + j > k) j= r.next();
            else i= l.next();
        }
        return false;
    }
};