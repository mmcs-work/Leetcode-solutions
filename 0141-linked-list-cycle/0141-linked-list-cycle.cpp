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
    bool hasCycle(ListNode *head) {
        ListNode *t, *r;
        t=head;r=head;
        if(!head)
            return false;
        
        do{
            r=r->next;
            if(r)
                r=r->next;
            else
                return false;
            t =t->next;
        }while(t && r && t!=r);
        if(t==r)
            return true;
        else
            return false;
    }
};