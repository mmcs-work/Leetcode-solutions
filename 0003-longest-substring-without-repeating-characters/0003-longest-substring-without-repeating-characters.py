class Solution:
    def lengthOfLongestSubstring(self, a: str) -> int:
        n = len(a)
        l = 0
        ans = 0
        ss = set()
        for r in range(n):
            if a[r] in ss:
                while a[r] in ss:
                    ss.remove(a[l])
                    l+=1
            ss.add(a[r])
            ans = max(ans,r-l+1)
        return ans        