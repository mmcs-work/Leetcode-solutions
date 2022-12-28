"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        m = {}
        t = head
        p = None
        s = None
        if not head:
            return head
        while t:
            n =  Node(t.val)
            if p:
                p.next = n
                p = p.next
            else:
                p = n
                s = p
            m[t]=p
            t = t.next
        t = head
        p = s
        while p:
            if t.random:
                p.random = m[t.random]
            t = t.next
            p = p.next
        
        return s
        
            