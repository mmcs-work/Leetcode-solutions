class Solution:
    def floodFill(self, g: List[List[int]], r: int, c: int, replacement: int) -> List[List[int]]:
        root=(r,c)
        q = deque([root])
        orig = g[r][c]
        vis = set()
        dev = [-1,0,1,0,-1]
        while len(q)>0:
            node = q.popleft()
            (x,y)=node
            vis.add((x,y))
            g[x][y]=replacement
            for i in range(4):
                nx,ny=x+dev[i],y+dev[i+1]
                if nx>=0 and ny>=0 and nx<len(g) and ny<len(g[0]) and (nx,ny) not in vis and g[nx][ny]==orig:
                    q.append((nx,ny))
        return g
        