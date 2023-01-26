class Solution:
    def topKFrequent(self, words: List[str], kk: int) -> List[str]:
        d=defaultdict(int)
        for w in words:
            d[w]+=1
        ans = []
        for k,v in d.items():
            ans.append([-v,k])
        ans = sorted(ans)
        print(ans)
        j = 0
        anss=[]
        for i in range(kk):
            if j <= len(ans)-1:
                anss.append(ans[j][1])
                j+=1
        return anss