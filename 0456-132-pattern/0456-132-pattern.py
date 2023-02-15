class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s = []
        cm = nums[0]
        
        for n in nums[1:]:
            while s and s[-1][0] <= n:
                s.pop()
            if s and n> s[-1][1]:
                return True
            s.append([n,cm])
            cm = min(cm,n)
        return False
        