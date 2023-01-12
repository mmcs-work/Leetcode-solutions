class Solution:
    def meetRequirement(self, n: int, lights: List[List[int]], req: List[int]) -> int:
        b = Counter()
        # e = []
        for l in lights:
          bb = max(0,l[0]-l[1])
          b[bb]+=1
          ee = min(n-1,l[0]+l[1])
          b[ee+1]-=1
        ct = 0
        ans = 0
        ansi=0
        for x in range(n):
          ct+=b[x]
          if ct>=req[x]:
            ans+=1
        return ans
          
        