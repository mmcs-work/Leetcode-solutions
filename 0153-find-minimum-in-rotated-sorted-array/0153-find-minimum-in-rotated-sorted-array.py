
class Solution:
    def findMin(self, arr: List[int]) -> int:
        if arr[0] < arr[-1]:
            return arr[0]
    
        l,r = 0,len(arr)-1
        ans = -1
        if len(arr) == 2:
            return arr[0] if arr[0]<arr[1] else arr[1]
        while l<=r:
            m = (l+r)//2
            if arr[m]>=arr[0]:
                l = m+1
            else:
                ans = m
                r = m-1
        return arr[ans]

