class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        m , n = len(s), len(t)
        dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
        for j in range(n):
            dp[0][j]= max(dp[0][j-1],int(s[0]==t[j]))
        for i in range(m):
            dp[i][0]=max(dp[i-1][0],int(s[i]==t[0]))
        
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=max(int(s[i]==t[j])+dp[i-1][j-1],dp[i][j-1],dp[i-1][j])
        return int(dp[m-1][n-1])