class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        dp={}
        def h(i,t):
            if (s-t) < t:
                return False
            if (s-t) == t:
                return True
            if (i,t) in dp:
                return dp[(i,t)]
            if i>= len(nums):
                return False
            dp[(i,t)]= h(i+1,t+nums[i]) or h(i+1,t)
            return dp[(i,t)]
        
        return h(0,0)
        # return dp[(0,0)]