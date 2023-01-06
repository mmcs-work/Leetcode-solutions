class Solution:
    def largestDivisibleSubset(self, a: List[int]) -> List[int]:
        a.sort()
        n = len(a)
        dp = [0]*n
        dp[0]=1
        p = [-1]*n
        for i in range(1,n):
            dp[i]=1
            for j in range(0,i):
                if a[i]%a[j] == 0:
                    if dp[j]+1>dp[i]:
                        dp[i]=dp[j]+1
                        p[i]=j
        m = dp.index(max(dp))                
        ans = []
        while m!=-1:
            ans.append(a[m])
            m = p[m]
        ans=ans[::-1]
        return ans