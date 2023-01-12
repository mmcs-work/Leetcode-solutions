class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        s = Counter()
        for u in updates:
          s[u[0]]+=u[2]
          s[u[1]+1]-=u[2]
        ans =[0]*length
        ct = 0
        sa = [0]*length
        for x in sorted(s.keys()):
          if x<length:
            ans[x]+=s[x]
        for i in range(length):
          sa[i]=ans[i]+sa[i-1]
        return sa