/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  Node* merge(Node* list1 , Node* list2){
      Node* dammy = new Node(-1);
      Node* res = dammy;
      while(list1 != NULL && list2 != NULL){
          if(list1->data < list2->data){
              res->bottom=list1;
              res = list1;
              list1= list1->bottom;
          } else {
              res->bottom=list2;
              res = list2;
              list2= list2->bottom;
          }
          res->next = NULL;
          
      }
          if(list1){
              res->bottom=list1;
          } else{
              res->bottom=list2;
          }
          if(dammy->bottom) dammy->bottom->next=NULL;
          
      return dammy->bottom;
  }
    Node *flatten(Node *head) {
        // Your code here
        if(head == NULL || head->next== NULL) return head;
        Node* mergehead = flatten(head->next);
        head = merge(head, mergehead);
        return head;
    }
};