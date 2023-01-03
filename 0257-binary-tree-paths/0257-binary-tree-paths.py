# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []

        def h(root, t,ans):
            t+=[str(root.val)]
            if not root.left and not root.right:
                ans.append("->".join(t))
                t.pop()
                return
            if root.left: h(root.left,t,ans)
            if root.right: h(root.right,t,ans)
            t.pop()
            return

        if root:
            h(root, [],ans)
        return ans