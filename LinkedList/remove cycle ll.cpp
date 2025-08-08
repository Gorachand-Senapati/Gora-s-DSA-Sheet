/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
// class Solution {
// public:
//     bool removeLoop(Node* head) {
//         Node* slow = head;
//         Node* fast = head;

//         // Detect cycle
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast)
//                 break;
//         }

//         if (fast == NULL || fast->next == NULL)
//             return false;  // No loop

//         // Find start of loop
//         slow = head;
//         Node* prev = NULL;
//         while (slow != fast) {
//             slow = slow->next;
//             prev = fast;
//             fast = fast->next;
//         }

//         // Remove loop
//         prev->next = NULL;
//         return true;
//     }
// };

class Solution {
public:
    void removeLoop(Node* head) {
        // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;//prev pointer null so break loop
    }
  }
};




