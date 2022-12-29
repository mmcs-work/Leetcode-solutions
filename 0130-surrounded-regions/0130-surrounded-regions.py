class Solution:
    def solve(self, b: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m,n = len(b),len(b[0])
        # v = [[False]*n for _ in range(m)]
        # red = []
        def dfs(i,j):
            b[i][j]="@"
            for x,y in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
                if x>=0 and x<m and y<n and y>=0 and b[x][y]=="O":
                    dfs(x,y)
        
        for i in range(m):
            for j in range(n):
                if ((i==0 or i==(m-1)) or (j==0 or j==(n-1))) and b[i][j]=="O":
                    dfs(i,j)
        for i in range(m):
            for j in range(n):
                if b[i][j]=="O":
                    b[i][j]="X"
                if b[i][j]=="@":
                    b[i][j]="O"
                
    