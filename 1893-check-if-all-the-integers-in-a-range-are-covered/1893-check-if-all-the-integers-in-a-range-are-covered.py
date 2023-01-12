class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
      ranges.sort()
      l = 0
      # ans = 0
      for x in range(left,right+1):
        while l<len(ranges) and not (x >= ranges[l][0] and x<= ranges[l][1]):
          l+=1
        if l == len(ranges):
          return False
        
      return True
        