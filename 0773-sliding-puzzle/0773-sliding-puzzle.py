class Solution:
    def slidingPuzzle(self, a: List[List[int]]) -> int:
        a = tuple(tuple(x) for x in a)
        q = deque()
        q.append(a)
        v=set()

        v.add(a)
        dist = 0
        magic = ((1,2,3),(4,5,0))

        def neighs(x):
            oof = []
            for i in range(2):
                for j in range(3):
                    if x[i][j]==0:
                        for d in [(1,0),(-1,0),(0,1),(0,-1)]:
                            ni,nj=i+d[0],j+d[1]
                            if ni>=0 and nj>=0 and ni<2 and nj<3:
                                xx =copy.deepcopy(x) #x[::]
                                xx[ni][nj],xx[i][j]=xx[i][j],xx[ni][nj]
                                # xx =x.copy()
                                oof.append(xx)
            return oof
        ans = []
        while q:
            nn = len(q)
            for _ in range(nn):
                x = q.popleft()
                if x == magic:
                    return dist
                x = list(list(xx)for xx in x)
                ans.append(x)
                for myn in neighs(x):
                    amyn = tuple(tuple(x) for x in myn)
                    if amyn not in v:
                        q.append(amyn)
                        v.add(amyn)
            dist+=1
    #     print([x for x in ans if x[0][0]==1 and x[0][1]==2])
        return -1        