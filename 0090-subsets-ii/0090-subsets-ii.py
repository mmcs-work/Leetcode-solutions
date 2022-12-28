class Solution:
    def subsetsWithDup(self, a: List[int]) -> List[List[int]]:
        n = len(a)
        a=sorted(a)
        ans=[]
        def h(i, t):
            if i >= n:
                ans.append(t[::])
                return
            h(i+1,t+[a[i]])
            while i<n and (i+1)<n and a[i]==a[i+1]:
                i+=1
            h(i+1,t)
            return
        h(0,[])
        return ans