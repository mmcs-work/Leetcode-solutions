class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        
        nr, nc = len(heights), len(heights[0])
        
        pacific_reachable = set()
        atlantic_reachable = set()
        
        def dfs(row,col, reachable):
            reachable.add((row,col))
            for (x,y) in [(1,0),(0,1),(-1,0),(0,-1)]:
                nx, ny = row+x,col+y
                if nx < 0 or nx>=nr or ny >=nc or ny<0:
                    continue
                if (nx,ny) in reachable:
                    continue
                if heights[nx][ny] < heights[row][col]:
                    continue
                dfs(nx,ny,reachable)
        
        for i in range(nr):
            dfs(i,0,pacific_reachable)
            dfs(i,nc-1,atlantic_reachable)
        for i in range(nc):
            dfs(0, i, pacific_reachable)
            dfs(nr - 1, i, atlantic_reachable)
        return list(pacific_reachable.intersection(atlantic_reachable))