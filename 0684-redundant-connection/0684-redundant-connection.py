class uf:
    def __init__(self,size):
        self.size = size
        self.root = [i for i in range(size+1)]
    def find(self,x):
        if x== self.root[x]:
            return x
        self.root[x]=self.find(self.root[x])
        return self.root[x]
    def union(self,x,y):
        rx = self.find(x)
        ry = self.find(y)
        if(rx!=ry):
            self.root[rx]=ry
    def conne(self,x,y):
        return self.find(x)==self.find(y)
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        # ufo = uf()
        ans = []
        mx = 0
        for u,v in edges:
            mx= max([u,v,mx])
        ufo = uf(mx)
        for u,v in edges:
            if not ufo.conne(u,v):
                ufo.union(u,v)
            else:
                ans.append([u,v])
        return ans[-1]
        