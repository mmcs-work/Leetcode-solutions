class Solution:
    def findAnagrams(self, o: str, c: str) -> List[int]:
        m,n = len(o),len(c)
        if n > m:
            return []

        ct = 0
        oo = defaultdict(int)
        cc = defaultdict(int)
        for x in c:
            cc[x]+=1
        l = 0
        r = 0

        def check(oo,cc):
    #         print(oo)
    #         print(cc)
            for k,v in cc.items():
                if v > 0:
                    if k not in oo:
                        return False
                    if oo[k]!=v:
                        return False
            return True
        ans = []
        while r < m:
            oo[o[r]]+=1
            if r-n >= 0:
                oo[o[r-n]]-=1
            if check(oo,cc):
                ans.append(r-n+1)
            r+=1
        return ans
