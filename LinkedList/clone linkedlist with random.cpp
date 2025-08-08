/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(head == NULL)return NULL;
        unordered_map<Node*, Node*>mpp;//pair making old val= newval
        Node* newhead = new Node(head->data);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        mpp[head]= newhead;//oldhead= newhead
        //copy next pointer
    while(oldtemp != NULL){
        Node* copynode = new Node(oldtemp->data);
        mpp[oldtemp] = copynode;//all pair copy in map
        newtemp->next = copynode;
        oldtemp= oldtemp->next;
        newtemp= newtemp->next;
    }
      //copy random pointer
      oldtemp=head; newtemp=newhead;
      while(oldtemp != NULL){
          newtemp->random = mpp[oldtemp->random];
          oldtemp= oldtemp->next;
          newtemp= newtemp->next;
      }
      return newhead;
    }
};