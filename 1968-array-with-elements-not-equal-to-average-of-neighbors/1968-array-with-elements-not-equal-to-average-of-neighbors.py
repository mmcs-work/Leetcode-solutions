class Solution:
    def rearrangeArray(self, a: List[int]) -> List[int]:
        a = sorted(a)
        n = len(a)
        o = n//2
        e = n - o
        ans = [0]*n
        ans[::2] = a[0:e]
        ans[1::2]= a[e:n]
        return ans
        