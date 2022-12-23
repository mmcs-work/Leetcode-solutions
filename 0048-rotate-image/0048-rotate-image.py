class Solution:
    def rotate(self, a: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r, c = len(a), len(a[0])
        for i in range(r):
            for j in range(c):
                if i!=j and i>j:
                    a[i][j],a[j][i] = a[j][i],a[i][j]
        
        for i in range(r):
            a[i].reverse()