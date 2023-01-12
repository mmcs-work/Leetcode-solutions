class Solution:
    def maxSumRangeQuery(self, nums: List[int], reqs: List[List[int]]) -> int:
        ans = [0]*(len(nums)+1)
        for l,r in reqs:
            ans[l]+=1
            if r+1<len(nums):
                ans[r+1]-=1
        for i in range(1,len(nums)):
            ans[i]+=ans[i-1]
        print(ans)
        ans.sort(reverse=True)
        f=0
        N = 1000000000+7
        for i,x in enumerate(sorted(nums,reverse=True)):
            f = (f+(x*ans[i])%N)%N
        return f