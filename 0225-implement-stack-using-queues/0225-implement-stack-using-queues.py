class MyStack:

    def __init__(self):
        self.q = []

    def push(self, x: int) -> None:
        self.q.append(x)

    def pop(self) -> int:
        n  =len(self.q)
        for i in range(n-1):
            x = self.q.pop()
            self.q.append(x)
        return self.q.pop()

    def top(self) -> int:
        if self.q:
            return self.q[-1]

    def empty(self) -> bool:
        return not (len(self.q) > 0) 


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()