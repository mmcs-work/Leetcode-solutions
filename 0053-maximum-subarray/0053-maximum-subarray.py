class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cs = ms = nums[0]
        
        for num in nums[1:]:
            cs = max(num, cs + num)
            ms = max(ms, cs)
        
        return ms