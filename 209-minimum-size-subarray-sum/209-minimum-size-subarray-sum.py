class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, r = 0, 0
        n = len(nums)
        ss = 0
        ans = 10**9
        # nums.sort()
        
        while r < n:
            ss += nums[r]
            if ss >= target:
                ans = min(ans,r-l+1)
                while ss >=target and l <=r:
                    ss-=nums[l]
                    ans = min(ans, r-l+1)
                    l+=1
            r+=1
        return ans if ans!=10**9 else 0
            