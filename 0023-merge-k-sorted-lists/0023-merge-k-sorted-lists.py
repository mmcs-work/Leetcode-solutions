# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        sent = ListNode()
        heap = []
        for i in range(len(lists)):
            l=lists[i]
            if l:
                heapq.heappush(heap,(l.val,i))
        head=sent
        while heap:
            pp=heapq.heappop(heap)
            sent.next = lists[pp[1]]
            sent = sent.next
            if lists[pp[1]].next:
                lists[pp[1]]=lists[pp[1]].next
                heapq.heappush(heap,(lists[pp[1]].val,pp[1]))
        return head.next
        