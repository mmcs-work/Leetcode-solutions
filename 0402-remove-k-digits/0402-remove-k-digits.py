class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        s = []
        for c in num:
            while k and s and s[-1]> c:
                s.pop()
                k-=1
            s.append(c)
        s = s[:len(s)-k]
        s = "".join(s)
        return str(int(s)) if s else "0"