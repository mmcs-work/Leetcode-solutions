class Solution:
    def subarraySum(self, a: List[int], t: int) -> int:
        ss = 0
        d = defaultdict(int)
        d[0]=1
        n = len(a)
        pref = [0]*n
        pref[0]=a[0]
        ct = 0
        for j in range(1,n):
            pref[j]=a[j]+pref[j-1]
        for r in range(n):
            x = pref[r]-t
            if x in d:
                ct+=d[x]
            d[pref[r]]+=1


        return ct
        