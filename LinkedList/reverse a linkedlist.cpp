/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // use 3 pointer
       Node* curr = head;
       Node* prev = NULL;
       Node* next = NULL;
        while(curr != NULL){
            next= curr->next;//1st next point node
            curr->next = prev;//here reverse the arrow 
            prev = curr;
            curr = next;//update prev and curr node
        }
        return prev;
    }
};