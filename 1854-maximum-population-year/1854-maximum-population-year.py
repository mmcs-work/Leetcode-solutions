class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        lm = Counter()
        for b,d in logs:
          lm[b]+=1
          lm[d]-=1
        ans = -inf
        t=0
        ansy = inf
        for x in sorted(lm.keys()):
            t+=lm[x]
            if t>ans:
              ans=t
              ansy=x
        return ansy
          