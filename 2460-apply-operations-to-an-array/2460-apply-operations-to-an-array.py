class Solution:
    def applyOperations(self, a: List[int]) -> List[int]:
        aa = []
        for i in range(len(a)-1):
            if a[i] == a[i+1]:
                a[i] *=2
                a[i+1] = 0
        for x in a:
            if x > 0:
                aa=aa+[x]
        return aa+[0]*(len(a)-len(aa))