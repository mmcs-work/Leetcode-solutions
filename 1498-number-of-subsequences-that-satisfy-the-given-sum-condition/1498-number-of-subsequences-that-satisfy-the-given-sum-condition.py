class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        n = len(nums)
        ans = 0
        r=n-1
        m = (10**9+7)
        for i,x in enumerate(nums):
            while (x+nums[r]) > target and i<=r:
                r-=1
            if r-i>=0:
                ans += pow(2,(r-i),m)
        return ans%m