class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        ns = set(nums)
        for n in ns:
            if n-1 not in ns:
                cs = 1
                p = n
                while p+1 in ns:
                    p+=1
                    cs+=1
                ans = max(ans,cs)
        return ans