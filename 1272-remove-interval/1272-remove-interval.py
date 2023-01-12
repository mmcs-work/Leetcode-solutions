class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        ans = []
        bb,ee = toBeRemoved
        for [b,e] in intervals:
            if not (e < bb or ee < b):
                if b < bb:
                    ans.append([b,bb])
                    # ans.append([ee,e])
                if ee < e:
                    ans.append([ee,e])
                
            else:
                ans.append([b,e])
        return ans
              
              