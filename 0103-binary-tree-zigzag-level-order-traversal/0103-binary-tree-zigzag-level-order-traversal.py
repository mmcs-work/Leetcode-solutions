# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        ans = []
        if not root:
            return ans
        q.append(root)
        s = 0
        while len(q)>0:
            sz = len(q)
            t = []
            for _ in range(sz):
                u = q.popleft()
                t.append(u.val)
                for v in [u.left,u.right]:
                    if v:
                        q.append(v)
            if s:
                t = t[::-1]
            ans.append(t[::])
            s = 1-s

        return ans        