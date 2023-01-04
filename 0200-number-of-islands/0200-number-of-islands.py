class Solution:
    def numIslands(self, g: List[List[str]]) -> int:
        def bfs(x,y,g):
            q = deque([(x,y)])
            while len(q)>0:
                x,y=q.popleft()
                g[x][y]="0"
                for d in [(-1,0),(1,0),(0,1),(0,-1)]:
                    nx = x+d[0]
                    ny = y+d[1]
                    if nx>=0 and ny>=0 and nx<m and ny<n and g[nx][ny]=="1":
                        q.append((nx,ny))
                        g[nx][ny]="0"


        m , n = len(g),len(g[0])
        island = 0
        for i in range(m):
            for j in range(n):
                if g[i][j]=="1":
                    bfs(i,j,g)
                    island+=1
        return island
        