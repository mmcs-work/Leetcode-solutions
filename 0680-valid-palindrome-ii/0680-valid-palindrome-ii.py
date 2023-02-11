class Solution:
    def validPalindrome(self, s: str) -> bool:
        l , r = 0, len(s)-1
        n =  len(s)
        if n == 1 or n ==2:
            return True
        while l < r:
            if s[l]!=s[r]:
                break
            else:
                l+=1
                r-=1
        if l == r:
            return True
        else:
            p = s[0:r]+s[r+1:n]
            q = s[0:l]+s[l+1:n]
            if p[::-1] == p:
                return True
            if q[::-1]==q:
                return True
            return False