class MyCalendarTwo:

    def __init__(self):
        self.s =Counter()

    def book(self, start: int, end: int) -> bool:
        self.s[start]+=1
        self.s[end]-=1
        ct = 0
        for x in sorted(self.s.keys()):
          ct+=self.s[x]
          if ct>=3:
            self.s[start]-=1
            self.s[end]+=1
            return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)