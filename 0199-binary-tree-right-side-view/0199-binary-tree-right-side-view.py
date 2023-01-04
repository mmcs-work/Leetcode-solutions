# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = deque()
        ans = []
        if root is None:
            return ans
        q.append(root)
        while len(q)>0:
            sz = len(q)
            lst = 0
            for _ in range(0,sz):
                u = q.popleft()
                lst = u.val
                for v in [u.left,u.right]:
                    if v:
                        q.append(v)
            ans.append(lst)
        return ans        