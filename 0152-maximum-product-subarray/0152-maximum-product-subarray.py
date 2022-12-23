class Solution:
    def maxProduct(self, a: List[int]) -> int:
        if len(a) ==0:
            return 0
        
        max_so_far = a[0]
        min_so_far = a[0]
        res = max_so_far
        
        for i in range(1,len(a)):
            temp = max(a[i],max_so_far*a[i],min_so_far*a[i])
            min_so_far = min(a[i],max_so_far*a[i],min_so_far*a[i])
            max_so_far = temp
            res = max(res, max_so_far)
        return res