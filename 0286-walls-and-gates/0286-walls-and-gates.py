class Solution:
    def wallsAndGates(self, r: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        q = deque()
        m,n = len(r),len(r[0])
        for i in range(m):
            for j in range(n):
                if r[i][j]==0:
                    q.append((i,j,0))
        v = [[0]*n for _ in range(m)]
        dv = v.copy()
        INF=2147483647
        while len(q)>0:
            x,y,d = q.popleft()
            v[x][y]=1
            for p,pp in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                if p>=0 and pp>=0 and p<m and pp<n and v[p][pp]==0 and r[p][pp]==INF:
                    r[p][pp]=min(r[p][pp],d+1)
                    q.append((p,pp,d+1))