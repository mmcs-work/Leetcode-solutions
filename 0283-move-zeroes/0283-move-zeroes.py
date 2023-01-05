class Solution:
    def moveZeroes(self, a: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(a)
        l,r=0,0
        while r<n:
            while r<n and a[r] ==0:
                r+=1
            if r>=n:
                break
            a[l],a[r]=a[r],a[l]
            l+=1
            r+=1
        