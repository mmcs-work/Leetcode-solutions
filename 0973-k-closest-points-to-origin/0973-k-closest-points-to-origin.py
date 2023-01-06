class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def dist(point):
            return -point[0] ** 2 - point[1] ** 2 # "-" for max heap

        max_heap = []
        for i in range(k):
            pt = points[i]
            heappush(max_heap, (dist(pt), pt))

        for i in range(k, len(points)):
            pt = points[i]
            # max_heap[0] is root of max heap, the point with largest distance
            # max_heap[0][0] is -distance
            if dist(pt) > max_heap[0][0]:
                heappop(max_heap)
                heappush(max_heap, (dist(pt), pt))

        res = []
        for _ in range(k):
            _, pt = heappop(max_heap)
            res.append(pt)

        return res

