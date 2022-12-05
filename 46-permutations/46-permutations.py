class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def find(i, nums):
            if i == n:
                ans.append(nums.copy())
            else:
                for j in range(i,n):
                    nums[j], nums[i] = nums[i], nums[j]
                    find(i+1,nums)
                    nums[i], nums[j] = nums[j], nums[i]
        ans=[]
        n = len(nums)
        find(0,nums)
        return ans
        