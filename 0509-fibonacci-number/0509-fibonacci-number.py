class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n==1:
            return 1
        fp = [0]*(n+1)
        fp[1]=1
        for i in range(2,n+1):
            fp[i]=fp[i-1]+fp[i-2]
        return fp[n]