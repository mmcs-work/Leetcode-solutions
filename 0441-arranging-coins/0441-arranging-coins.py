class Solution:
    def arrangeCoins(self, n: int) -> int:
        lo , hi = 1,n
        ans = -1
        while lo <= hi:
            m = lo+(hi-lo)//2
            if m*(m+1) <= 2*n:
                ans = max(ans,m)
                lo= m+1
            else:
                hi = m -1
        return ans
        