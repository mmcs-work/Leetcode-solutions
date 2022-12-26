"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        m ={}
        def dfs(node):
            if node in m:
                return m[node]
            clon = Node(node.val)
            m[node]=clon
            for x in node.neighbors:
                t = dfs(x)
                clon.neighbors.append(t)
            return clon
        return dfs(node) if node else None