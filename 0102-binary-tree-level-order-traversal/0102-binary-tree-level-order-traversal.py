# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q= deque()
        ans = []
        if root is None:
            return ans
        q.append(root)
        while len(q)>0:
            sz = len(q)
            t = []
            while sz > 0:
                sz-=1
                u = q.popleft()
                t.append(u.val)
                if u.left: q.append(u.left)
                if u.right: q.append(u.right)
            ans.append(t[::])
        return ans        