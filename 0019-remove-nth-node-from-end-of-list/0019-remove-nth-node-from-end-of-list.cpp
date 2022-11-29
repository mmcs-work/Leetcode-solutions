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
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        ListNode* t=h, *p = h;
        for(int i = 1; i <= n; i++)
            t=t->next;
        while(t and t->next!=NULL){
            t=t->next;
            p=p->next;
        }
        if(t == NULL){
            return h->next;
        }
        ListNode* z = p->next->next; 
        p->next = z;
        return h;
    }
};