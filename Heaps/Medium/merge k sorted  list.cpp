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
//make custom comparator
class compare{
public: 
//operator+	lets you use a + b , operator==	lets you use a == b  ,operator()	lets you use obj(a, b) like a function
   bool operator()(ListNode* a , ListNode* b){
    return a->val > b->val;//if a >b true else false
   }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> pq;//make linkedlist min heap using comapre
        for(auto list: lists){
            if(list != NULL){
                pq.push(list);//push all linkedlist head value and that are sorted in pq
            }
        }
        //make a linked list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;//tail create
        while(!pq.empty()){
            ListNode* smallest = pq.top();//extract smallest
            pq.pop();
            tail->next = smallest;
            tail= tail->next;
            if(smallest->next != NULL){//again push head next values
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};