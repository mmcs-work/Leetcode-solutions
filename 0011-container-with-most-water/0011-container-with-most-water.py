class Solution:
    def maxArea(self, h: List[int]) -> int:
        l,r = 0, len(h)-1
        ans = 0
        while l < r:
            ans = max(ans, (r-l)*min(h[r],h[l]))
            if h[l]<h[r]:
                l+=1
            else:
                r-=1
        return ans