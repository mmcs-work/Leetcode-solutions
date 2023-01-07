class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        
        @lru_cache(None)
        def dp(left,right):
            if right - left < 0:
                return 0
            res = 0
            for i in range(left,right+1):
                gain = nums[left-1]*nums[i]*nums[right+1]
                remaining = dp(left,i-1)+dp(i+1,right)
                res = max(res, remaining+gain)
            return res
        return dp(1,len(nums)-2)