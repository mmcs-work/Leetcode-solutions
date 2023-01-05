class Solution:
    def removeDuplicates(self, a: List[int]) -> int:
        l,r=0,1
        n = len(a)
        while r<n:
            while r<n and a[r]==a[r-1]:
                r+=1
            if r < n:
                l+=1
                a[l]=a[r]
            r+=1
        return l+1
        