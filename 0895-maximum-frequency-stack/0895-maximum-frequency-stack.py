class FreqStack:

    def __init__(self):
        self.freq = collections.Counter()
        self.group = collections.defaultdict(list)
        self.mf = 0

    def push(self, val: int) -> None:
        self.freq[val] = self.freq[val]+1
        f= self.freq[val]
        if self.freq[val] > self.mf:
            self.mf = self.freq[val]
        self.group[f].append(val)
    def pop(self) -> int:
        x = self.group[self.mf].pop()
        self.freq[x] -= 1
        if not self.group[self.mf]: #if list is empty
            self.mf -= 1

        return x


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()