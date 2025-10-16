class Solution {
public:
    Node* connect(Node* root) {
        if(root== NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
           Node* rightNode= NULL;
            for(int i=0;i<sz;i++){
               Node* curr= q.front();
                q.pop();
                curr->next= rightNode;
                rightNode= curr;
                if(curr->right){
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};

//O(1) space
class Solution {
public:
    Node* connect(Node* root) {
        auto head = root;
        for(; root; root = root -> left) 
            for(auto cur = root; cur; cur = cur -> next)   // traverse each level - it's just BFS taking advantage of next pointers          
                if(cur -> left) {                          // update next pointers of children if they exist               
                    cur -> left -> next = cur -> right;
                    if(cur -> next) cur -> right -> next = cur -> next -> left;
                }
                else break;                                // if no children exist, stop iteration                                                  
        
        return head;
    }
};