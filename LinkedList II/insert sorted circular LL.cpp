/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newnode = new Node(data);
        // Case: Empty list
        if (head == NULL) {
            newnode->next = newnode;
            return newnode;
        }
        Node* temp = head;
        // Case: Insert before head (smallest element)
        if (newnode->data < temp->data) {
            // Find tail
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
            return head;
        }
        // Normal insertion
        while (temp->next != head) {
            if (temp->data <= newnode->data && newnode->data <= temp->next->data) {
                newnode->next = temp->next;
                temp->next = newnode;
                return head;
            }
            temp = temp->next; // Move forward
        }
        // If we reach here, newnode is the largest, insert at end
        temp->next = newnode;
        newnode->next = head;
        return head;
    }
};