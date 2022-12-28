class Solution:
    def change(self, amt: int, coins: List[int]) -> int:
        dp = [0]*(amt+1)
        dp[0]=1
        for c in coins:
            for x in range(c,amt+1):
                dp[x]+=dp[x-c]
        return dp[amt]
            
            