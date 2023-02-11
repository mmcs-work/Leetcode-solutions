# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, h: Optional[ListNode]) -> bool:
        f = h
        s = h
        while f and f.next:
            f = f.next.next
            s = s.next
            
        prev = None
        while s:
            t = s.next
            s.next = prev
            prev = s
            s = t
        l = h
        r = prev
        
        while r:
            if r.val != l.val:
                return False
            r = r.next
            l = l.next
        return True