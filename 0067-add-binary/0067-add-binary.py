class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a,b = a[::-1],b[::-1]
        c = 0
        res=""
        for i in range(max(len(a),len(b))):
            aa = ord(a[i])-ord('0') if i < len(a) else 0
            bb = ord(b[i])-ord('0') if i < len(b) else 0
            
            t = aa+bb+c
            ans = str(t%2)
            res=str(ans)+res
            c = t//2
            
        if c:
            res="1"+res
        return res
            