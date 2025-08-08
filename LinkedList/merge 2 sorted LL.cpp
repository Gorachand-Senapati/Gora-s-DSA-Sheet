class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        //base case
        if(head1 == NULL || head2 == NULL){
            return head1== NULL ? head2:head1;
        }; //If head1 is NULL, then return head2. Otherwise, return head1. if both null return null
        if(head1->data <= head2->data){
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        } else{ //if head2 small
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};