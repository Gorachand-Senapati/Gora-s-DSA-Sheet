class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow =head;
        ListNode* fast = head;
        for(int i=0;i<n;i++){ //n node ahead
            fast= fast->next;
        }
        if(fast == NULL){ //means delete head node
            ListNode* newhead = head->next;
            return newhead;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast= fast->next;
        }
        ListNode*delnode = slow->next;
        slow->next= slow->next->next;
        delete delnode;
        return head;
    }
};