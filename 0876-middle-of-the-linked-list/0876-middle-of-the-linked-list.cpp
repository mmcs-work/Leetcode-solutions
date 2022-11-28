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
    ListNode* middleNode(ListNode* head) {
        ListNode *t = head;
        int ct = 0;
        while(t){
            t = t->next;
            ct++;
        }
        ct/=2;
        t =head;
        while(ct--){
            t=t->next;
        }
        return t;
    }
};