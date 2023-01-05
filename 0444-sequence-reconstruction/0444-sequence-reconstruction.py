class Solution:
    def sequenceReconstruction(self, original: List[int], seqs: List[List[int]]) -> bool:
        original = [o-1 for o in original]
        seqs = [[ss-1 for ss in s] for s in seqs]
        n = len(original)
        g = [[] for _ in range(n)]
        indegree = [0]*n
        for s in seqs:
            subseqlen = len(s)
            for i in range(0,subseqlen-1):
                g[s[i]].append(s[i+1])
                indegree[s[i+1]]+=1

        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        while q:
            if len(q)>1:
                return False
            u = q.popleft()
            for v in g[u]:
                indegree[v]-=1
                if indegree[v] == 0:
                    q.append(v)
        for i in range(n):
            if indegree[i] > 0:
                return False
        return True
