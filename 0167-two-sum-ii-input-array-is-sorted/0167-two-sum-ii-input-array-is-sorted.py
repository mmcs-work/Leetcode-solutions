class Solution:
    def twoSum(self, a: List[int], t: int) -> List[int]:
        n = len(a)
        l,r=0,n-1
        while l<n and r>=0 and (a[l]+a[r])!=t:
            if t < (a[l]+a[r]):
                r-=1
            else:
                l+=1
        if l<n and r>=0:
            return [l+1,r+1]
        return []
