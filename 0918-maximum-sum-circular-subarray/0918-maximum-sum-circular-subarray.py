class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # nums+=nums
        # print(nums)
        L,R = 0, 0
        mx = nums[0]
        mn = nums[0]
        N = len(nums)
        cur = 0
        curn = 0
        for R in range(N):
            if cur < 0:
                cur =0
            if curn > 0:
                curn = 0
            cur+=nums[R]
            curn +=nums[R]
            if cur >= mx:
                mx = cur
            if curn <= mn:
                mn =curn
        
        return max(mx,sum(nums)-mn) if mx >=0 else min(mx,sum(nums)-mn) 
                    