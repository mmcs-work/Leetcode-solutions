class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        d={}
        if n == 0:
            return len(tasks)
        for x in tasks:
            if x in d:
                d[x]+=1
            else:
                d[x]=1
        
        mx = 0
        for x,y in d.items():
            if y > mx:
                mx = y
        
        ct=0
        for x,y in d.items():
            if y == mx:
                ct+=1
        
        return max((mx-1)*n+mx+ct-1,len(tasks))