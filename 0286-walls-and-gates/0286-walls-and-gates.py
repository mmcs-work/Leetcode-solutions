class Solution:
    def wallsAndGates(self, g: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m,n = len(g),len(g[0])
        q=deque()
        inf = 2147483647 
        vis=set()
        for i in range(m):
            for j in range(n):
                if g[i][j]==0:
                    q.append((i,j))
                    vis.add((i,j))
        dist = 0
        while q:
            nn = len(q)
            for _ in range(nn):
                x,y=q.popleft()
                g[x][y]=dist
                for di in [(-1,0),(1,0),(0,1),(0,-1)]:
                    nx,ny=x+di[0],y+di[1]
                    if nx>=0 and ny>=0 and nx<m and ny<n and (nx,ny) not in vis and g[nx][ny]==inf:
                        q.append((nx,ny))
                        vis.add((nx,ny))
            dist+=1
        return g
