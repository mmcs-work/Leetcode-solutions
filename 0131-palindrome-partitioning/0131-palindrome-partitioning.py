class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans=[]
        n = len(s)
        def h(i,t,sl):
            if i>=n:
                if t == t[::-1] and len(t)>0:
                    sl += [t]
                else:
                    return
                ans.append(sl[::])
                return
            ssl= sl[:]
            h(i+1,t+s[i],ssl)
            m = t+s[i]
            if m[::-1]==m:
                h(i+1,"",sl+[m])
        h(0,"",[])
        return ans