class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def h(i, t):
            if i >= len(nums):
                ans.append(t)
                return
            
            h(i+1,t+[nums[i]])
            h(i+1,t)
            return
        h(0,[])
        return ans
            