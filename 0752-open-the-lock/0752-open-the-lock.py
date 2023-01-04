class Solution:
    def openLock(self, no: List[str], t: str) -> int:
        if t in no or "0000" in no:
            return -1
        vis = set()
        vis.add("0000")
        q = deque(["0000"])
        dist = 0
        ans = []
        while q:
            nn = len(q)
            for _ in range(nn):
                ms = q.popleft()
                ans.append(ms)
                if ms == t:
                    return dist
                msl = list(ms)
                omsl = [int(x) for x in msl]
                for i in range(4):
                    for j in [+1, -1]:
                        msl=omsl.copy()
                        msl[i] += (j + 10)
                        msl[i] %= 10
                        dmsl = [str(x) for x in msl]
                        ams = "".join(dmsl)
                        if ams not in vis and ams not in no:
                            vis.add(ams)
                            q.append(ams)
            dist += 1

        return -1
        