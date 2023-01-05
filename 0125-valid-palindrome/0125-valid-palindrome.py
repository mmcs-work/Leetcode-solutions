class Solution:
    def isPalindrome(self, s: str) -> bool:
        n=len(s)
        s=s.lower()
        l,r= 0,n-1
    #     print(s)
        while l<=r and l>=0 and r<n:
            while l<n and not s[l].isalnum() and l<=r:
                l+=1
            while r>=0 and not s[r].isalnum() and l<=r:
                r-=1
    #         print(l,r)
            if l<n and r>=0 and l<=r and s[l]!=s[r]:
                return False
            l+=1
            r-=1
        return True
        