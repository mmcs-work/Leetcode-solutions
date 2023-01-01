class Solution:
    def closetTarget(self, w: List[str], t: str, s: int) -> int:
        n = len(w)
        m = []
        ss = s
        i = s+1
        ct = 1
        i%=n
        if t not in w:
            return -1
        if w[s]==t:
            return 0
        while i!=s:
            if w[i]==t:
                m.append(ct)
                break
            i+=1
            i%=n
            ct+=1
        i = s-1
        ct = 1
        i%=n
        while i!=s:
            if w[i] ==t:
                m.append(ct)
                break
            i-=1
            if i==-1:
                i = n-1
            ct+=1
        return min(m)
    