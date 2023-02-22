class Solution:
    def minOperations(self, n: int) -> int:
        def dp(x):
            if x == 0: return 0
            if (x & (x - 1)) == 0: return 1
            return min(dp(x + (x & -x)), dp(x - (x & -x))) + 1
        return dp(n)