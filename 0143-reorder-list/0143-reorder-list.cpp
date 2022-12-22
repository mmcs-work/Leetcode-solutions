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
    void reorderList(ListNode* head) {
        queue<ListNode *> q;
        stack<ListNode *> s;
        
        int len = 0;
        ListNode *t = head;
        
        while(t != NULL){
            t = t->next;
            len++;
        }
        
        t = head;
        int m = len/2, i = 0;
        while(i < m){
            q.push(t);
            t = t->next;
            i++;
        }
        ListNode *odd =NULL;
        if( (len%2) == 1){
            odd = t;
            t = t->next;
        }
        while(t!=NULL){
            s.push(t);
            t = t->next;
        }
        
        ListNode *sent = new ListNode();
        t = sent;
        i = 0;
        ListNode *prev = NULL;
        if(len%2 == 1)
            len--;
        while(len--){
            if(i % 2 == 0){
                auto p = q.front();
                q.pop();
                t->next = p;
                prev = t;
                t = t->next;
            }
            else{
                auto p = s.top();
                s.pop();
                t->next = p;
                prev = t;
                t = t->next;
            }
            i++;
        }
        if(t)
            t->next = odd;
        else
            prev->next = odd;
        if(odd)
            odd->next = NULL;
        ListNode * ans = sent->next;
        // delete(sent);
        // return ans;
        head = ans;
    }
};