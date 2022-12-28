class TimeMap:

    def __init__(self):
        self.map = {}
        # self.mapt = {}

    def set(self, key: str, value: str, t: int) -> None:
        if key not in self.map:
            self.map[key]=[]
        self.map[key].append((t,value))
        
    def get(self, key: str, t: int) -> str:
        if key not in self.map:
            return ""
        a = self.map[key]
        l,r = 0,len(a)-1
        # 0 1 2 
        while l<r:
            m = (l+r)//2
            if a[m][0] == t:
                return a[m][1]
            elif a[m][0] > t:
                r = m-1
            else:
                l = m+1
        if a[l][0] > t:
            if l>=1:
                return a[l-1][1]
            else:
                return ""
        else:
            return a[l][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)