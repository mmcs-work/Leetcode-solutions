# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        q = deque()
        if root is None:
            return 0
        q.append(root)
        d = 1
        ans = inf
        while len(q) > 0:
            sz = len(q)
            for _ in range(sz):
                u = q.popleft()
                if u.left is None and u.right is None:
                    ans = min(ans,d)
                    break
                for v in [u.left, u.right]:
                    if v:
                        q.append(v)
            if ans is not inf:
                return ans
            d+=1
        return ans