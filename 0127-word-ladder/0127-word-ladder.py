class Solution:
    def ladderLength(self, begin: str, end: str, word_list: List[str]) -> int:
        if begin == end:
            return 0

        if end not in word_list:
            return 0
        word_list = set(word_list)
        q = deque([begin])
        vis = set()
        vis.add(begin)
        dist = 1
        while q:
            nn = len(q)
            for _ in range(nn):
                x = q.popleft()
                if x in word_list and x == end:
                    return dist
                for i in range(len(x)):
                    for p in range(ord('a'),ord('z')+1):
                        if x[i] != chr(p):
                            s = x[0:i]+chr(p)+x[i+1:]
                            if s not in vis and s in word_list:
                                if s == end:
                                    return dist+1
                                vis.add(s)
                                q.append(s)
            dist+=1

        return 0        