class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [0]*n
        for i in range(n-2,-1,-1):
            for j in range(i+1,n):
                dp[i] = max(dp[i],(prices[j]-prices[i])+(dp[j+2] if j+2 < n else 0))
            dp[i]=max(dp[i],dp[i+1] if i+1<n else 0)
        
        return dp[0]