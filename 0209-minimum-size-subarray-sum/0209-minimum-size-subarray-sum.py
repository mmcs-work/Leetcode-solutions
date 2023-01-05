class Solution:
    def minSubArrayLen(self, t: int, a: List[int]) -> int:
        l = 0
        n =len(a)
        ss = 0
        ans = inf
        for r in range(n):
            ss+=a[r]
            while ss >= t:
                ans = min(ans,r-l+1)
                ss-=a[l]
                l+=1
        return ans if ans !=inf else 0
        