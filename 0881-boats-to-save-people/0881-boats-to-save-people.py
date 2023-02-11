class Solution:
    def numRescueBoats(self, p: List[int], limit: int) -> int:
        n = len(p)
        l , r  = 0, n-1
        carried = 0
        boats  =0
        p = sorted(p)
        while carried < n:
            if p[l]+p[r]> limit:
                r-=1
                carried+=1
            else:
                l+=1
                r-=1
                carried+=2
            boats+=1
        return boats
            