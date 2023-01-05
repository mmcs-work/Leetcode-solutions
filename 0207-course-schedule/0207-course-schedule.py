class Solution:
    def canFinish(self, n: int, pr: List[List[int]]) -> bool:
        g = [[] for _ in range(n)]
        ind = [0]*n
        for p in pr:
            g[p[0]].append(p[1])
            ind[p[1]]+=1
        q = deque()
        for i in range(n):
            if ind[i]==0:
                q.append(i)
        while q:
            u = q.popleft()
            for v in g[u]:
                ind[v]-=1
                if ind[v]==0:
                    q.append(v)
        for i in range(n):
            if ind[i]>0:
                return False
        return True
        