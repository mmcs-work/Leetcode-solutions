class Solution:
    def minFlips(self, s: str) -> int:
        s+=s
        s1 = ""
        s2 = ""
        N = len(s)
        for i in range(N):
            s1+=str(i%2)
            s2+=str(1-i%2)
        ans1=0
        ans2=0
        ans =inf
        n = N//2
        for i in range(N):
            if s1[i]!=s[i]:
                ans1+=1
            if s2[i]!=s[i]:
                ans2+=1
            if i >= n:
                if s1[i-n] != s[i-n]:
                    ans1-=1
                if s2[i-n] != s[i-n]:
                    ans2-=1
            if i>=n-1:
                ans = min([ans, ans1,ans2])
        return ans