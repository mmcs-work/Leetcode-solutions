class Solution:
    def myPow(self, x: float, n: int) -> float:
        def h(x,n):
            if n==0:
                return 1
            b = h(x,n//2)
            if n%2:
                return x*b*b
            else:
                # b = h(x,n//2)
                return b*b
        if n < 0:
            return 1/h(x,-n)
        return h(x,n)