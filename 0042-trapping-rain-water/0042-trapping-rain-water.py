class Solution:
    def trap(self, h: List[int]) -> int:
        if not h:
            return 0

        l, r = 0, len(h) - 1
        lm, rm = h[l], h[r]
        res = 0
        while l < r:
            if lm < rm:
                l += 1
                lm = max(lm, h[l])
                res += lm - h[l]
            else:
                r -= 1
                rm = max(rm, h[r])
                res += rm - h[r]
        return res
