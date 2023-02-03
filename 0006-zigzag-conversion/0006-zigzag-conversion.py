class Solution:
    def convert(self, s: str, nr: int) -> str:
        ans = [[] for x in range(nr)]
        row =0
        dir = 1
        if nr == 1:
            return s
        for c in s:
            ans[row].append(c)
            row+=dir
            if row ==0 or row == nr-1:
                dir*=-1
        
        return "".join(["".join(ro) for ro in ans])