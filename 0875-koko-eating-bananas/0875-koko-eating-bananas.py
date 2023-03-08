class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l,r = 1,max(piles)
        res=r
        while l<=r:
            m = (l+r)//2
            time_taken = sum([int(math.ceil(x/m)) for x in piles])
            if time_taken <= h:
                res=min(res,m)   
                r = m-1
            else:
                l=m+1
        return res