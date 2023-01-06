class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        for p in points:
            d = p[0]**2+p[1]**2
            res.append((d,p))
        heapq.heapify(res)
        ans=[]
        for kk in range(k):
            tt = heapq.heappop(res)
            ans.append(tt[1])
        return ans

