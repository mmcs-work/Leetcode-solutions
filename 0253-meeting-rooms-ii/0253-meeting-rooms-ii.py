class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        starts = sorted([i[0] for i in intervals])
        ends = sorted([i[1] for i in intervals])
        
        ct=0
        res=0
        s = 0
        e=0
        while s < len(starts):
            if starts[s] < ends[e]:
                ct+=1
                s+=1
            else:
                ct-=1
                e+=1
            res=max(res,ct)
        return res