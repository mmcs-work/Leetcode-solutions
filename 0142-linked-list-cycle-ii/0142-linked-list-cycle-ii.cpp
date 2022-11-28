/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* r, *t;
        r=t=head;
        do{
            r=r->next;
            if(r)
                r=r->next;
            else
                return NULL;
            t=t->next;
        }
        while(r && t && r!=t);
            
        if(r==t)
        {
            r=head;
            while(r!=t){
                r=r->next;
                t=t->next;
            }
            return r;
        }
        else
            return NULL;
    }
};