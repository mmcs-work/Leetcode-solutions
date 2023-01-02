class Solution:
    def isPerfectSquare(self, n: int) -> bool:
        l,r = 0, n
        sq = False
        while l<=r:
            m = (l+r)//2
            if m*m <= n:
                sq = True if m*m == n else sq
                l = m+1
            else:
                r = m-1
        return sq