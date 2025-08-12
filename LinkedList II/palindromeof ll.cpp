/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLl(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while (temp != NULL) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true; // if 0 or 1 element

        // find the middle of ll
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {  // ✅ fixed condition
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse from middle->next
        ListNode* newhead = reverseLl(slow);
        ListNode* first = head;
        ListNode* second = newhead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseLl(newhead); // restore list before return
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseLl(newhead); // restore list
        return true;
    }
};