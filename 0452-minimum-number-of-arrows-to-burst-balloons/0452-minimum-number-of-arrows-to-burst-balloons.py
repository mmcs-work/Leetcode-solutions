class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        events = []
        for i,[x,y] in enumerate(points):
          events.append([x,+1,i])
          events.append([y+1,-1,i])
        ans = 0
        # temp = 0
        ss = set()
        for s,t,i in sorted(events):
          if t == +1:
            ss.add(i)
          else:
            if i in ss:
              ss.clear()
              ans+=1
        if ss:
          ans+=1
        return ans
          