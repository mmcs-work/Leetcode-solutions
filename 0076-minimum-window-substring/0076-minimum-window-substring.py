class Solution:
    def minWindow(self, o: str, c: str) -> str:
        def mm(ol,cl):
            for i in range(60):
                if cl[i]>0:
                    if not (ol[i]>=cl[i]):
                        return False
            return True

        ol = [0]*60
        cl = [0]*60
        l = 0
        n = len(o)
        a = ord('a')
        nc = len(c)
        mn = inf
        mns = ''
        ans = []
        for x in c:
            cl[ord(x)-a]+=1
        for r in range(n):
            ol[ord(o[r])-a]+=1
            while mm(ol,cl):
                temp = o[l:r+1]
                if len(temp)<mn: 
                    mn=len(temp)
                    mns=temp
                if len(temp) == mn:
                    if temp < mns:
                        mns=temp
    #             ans.append(mns)
                ol[ord(o[l])-a]-=1
                l+=1
    #     ans = sorted(ans,key=lambda x: (len(x),x))
    #     print(ans)
        return mns if mns else ""