# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1:
            return l2
        if not l2:
            return l1
        head = ListNode()
        t = head
        c = 0
        s = 0
        while l1 and l2:
            s =  l1.val+l2.val+c
            c = int(s/10)
            s = s%10
            t.next= ListNode(s)
            t = t.next
            l1 = l1.next
            l2 = l2.next
        
        while l1:
            s =  l1.val+c
            c = int(s/10)
            s = s%10
            t.next= ListNode(s)
            t = t.next
            l1 = l1.next
        
        while l2:
            s =  l2.val+c
            c = int(s/10)
            s = s%10
            t.next= ListNode(s)
            t = t.next
            l2 = l2.next
        
        while c:
            t.next= ListNode(c)
            t = t.next
            c = 0
            
        return head.next
        
        
            
        