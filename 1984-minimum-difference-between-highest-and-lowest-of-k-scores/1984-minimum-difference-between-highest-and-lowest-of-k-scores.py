class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        n = len(nums)
        ans = []
        for i in range(n):
            if i+k <= n:
                ans.append(-min(nums[i:i+k])+max(nums[i:i+k])) 
        return min(ans)