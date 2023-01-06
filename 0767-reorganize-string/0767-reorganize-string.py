class Solution:
    def reorganizeString(self, s: str) -> str:
        d = Counter(s)
        heap = []
        for k,v in d.items():
            heap.append((-v,k))
        heapify(heap)
        ans=[]
        while heap:
            v, c = heappop(heap)
            v=-v
            v-=1
            ans.append(c)
            if heap:
                t = heappop(heap)
                vv=-t[0]
                vv-=1
                ans.append(t[1])
                if vv:
                    heappush(heap,(-vv,t[1]))
            if v:
                heappush(heap,(-v,c))
            # ans.append(c)
        for i in range(1,len(ans)):
            if ans[i] == ans[i-1]:
                return ""
        return ''.join(ans)
        