class Solution:
    def jump(self, a: List[int]) -> int:
        n = len(a)
        inf = 10000000
        dp = [inf]*n
        dp[n-1]=0
        for i in range(n-2,-1,-1):
            ms = a[i]
            for k in range(1,ms+1):
                if i+k < n and dp[i+k] < inf:
                    dp[i] = min(dp[i],dp[i+k]+1)
        return dp[0]