class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        def bfs(tx,ty,d):
            # if tx == 0 and ty==0:
            #     return 0
            d.add((0,0))
            q = deque([(0,0)])
            dist = 0
            dir =[(-1,2),(+1,2),(-1,-2),(+1,-2),(-2,1),(2,1),(-2,-1),(2,-1)]
            while len(q)>0:
                nn = len(q)
                for _ in range(nn):
                    x,y = q.popleft()
                    if (x,y) == (tx,ty):
                        return dist
                    for dip in dir:
                        nx = x + dip[0]
                        ny = y + dip[1]
                        # if tx == nx and ty == ny:
                        #     return dist + 1
                        if (nx,ny) not in d:
                            # if tx == nx and ty==ny:
                            #     return dist+1
                            d.add((nx,ny))
                            q.append((nx,ny))
                dist+=1
        d =set()
        return bfs(x,y,d)
        