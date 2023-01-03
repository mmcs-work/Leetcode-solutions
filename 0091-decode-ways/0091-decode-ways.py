class Solution:
    def numDecodings(self, d: str) -> int:
        def h(i):
            if i>=len(d):
                return 1
            if i in dd:
                return dd[i]
            dd[i] = 0
            for j in range(i,min(len(d),i+2)):
                t = d[i:j+1]
                if t in mm and (1<= int(t) <= 26):
                   dd[i]+=h(j+1)
            return dd[i]
        dd = {}
        mm = {}
        for i in range(1,27):
            mm[str(i)]=i
        return h(0)        