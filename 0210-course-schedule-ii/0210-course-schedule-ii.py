class Solution:
    def findOrder(self, V: int, edges: List[List[int]]) -> List[int]:
        inq = [0]*V
        g = defaultdict(list)
        for x,y in edges:
            g[y].append(x)
            inq[x]+=1
        q=deque()
        for i in range(V):
            if inq[i]==0:
                q.append(i)
        ct = 0
        ans = []
        while len(q)>0:
            u = q.popleft()
            inq[u]-=1
            for v in g[u]:
                if inq[v]>0:
                    inq[v]-=1
                if inq[v]==0:
                    q.append(v)
            ct+=1
            ans.append(u)
        if ct!=V:
            return []
        return ans