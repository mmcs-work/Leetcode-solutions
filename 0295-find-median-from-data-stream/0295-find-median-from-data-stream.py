# class MedianFinder:

#     def __init__(self):
        

#     def addNum(self, num: int) -> None:
        

#     def findMedian(self) -> float:
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

class MedianFinder:
    def __init__(self):
        self.minheap = []
        self.maxheap = []
    def equalize(self):
        if (len(self.maxheap) + len(self.minheap)) % 2 == 0:
            deslen = (len(self.maxheap) + len(self.minheap)) / 2
            if len(self.maxheap) > deslen:
                while len(self.maxheap) > deslen:
                    negv = heappop(self.maxheap)
                    v = -negv
                    heappush(self.minheap, v)
            else:
                while len(self.minheap) > deslen:
                    v = heappop(self.minheap)
                    heappush(self.maxheap, -v)
    def addNum(self, num: int) -> None:
        # WRITE YOUR BRILLIANT CODE HERE
        if self.maxheap:
            if num <= (-self.maxheap[0]):
                heappush(self.maxheap, -num)
            else:
                heappush(self.minheap, num)
        else:
            heappush(self.maxheap,-num)
        self.equalize()
        return

    def findMedian(self) -> float:
        # ALSO HERE
        deslen = (len(self.maxheap) + len(self.minheap)) % 2
        if deslen == 1:
            if len(self.maxheap) > len(self.minheap):
                return -self.maxheap[0]
            else:
                return self.minheap[0]
        else:
            return (-self.maxheap[0]+self.minheap[0])/2.0

