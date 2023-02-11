class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        r = len(grid)
        c = len(grid[0])
        n = r*c
        
        mm = [[0]*c for _ in range(r)]
        
        for i in range(r):
            for j in range(c):
                pos1d = i*c+j
                pos1d+= k
                pos1d %= n
                mm[pos1d//c][pos1d%c] = grid[i][j]
        return mm