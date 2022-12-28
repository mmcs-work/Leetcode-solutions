class Solution:
    def combinationSum2(self, a: List[int], target: int) -> List[List[int]]:
        ans, n =[], len(a)
        a = sorted(a)
        def h(i,s,t):
            if s>target:
                return
            if i>=n:
                if s == target:
                    ans.append(t[::])
                return
            h(i+1,s+a[i],t+[a[i]])
            while i+1<n and a[i]==a[i+1]:
                i+=1
            h(i+1,s,t)
        h(0,0,[])
        return ans