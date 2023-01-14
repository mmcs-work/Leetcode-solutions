class Solution:
    def reversePairs(self, a: List[int]) -> int:
        l,r = 0,len(a)-1
        def ms(a,l,r):
            # print(a)
            # print(l,"----",r)
            ans=0
            m = (l+r)//2
            if l==r:
                return ans
            if l > r:
                return ans
            ans+= ms(a,l,m)
            ans+=ms(a,m+1,r)
            
            b = [0]*(r-l+1)
            p,q,rr=l,m+1,0
            # ans = 0
            i,j = l,m+1
            if (l==3 and r==4) or (l==0 and r==4):
                mmm=1
            while i<=m and j<=r:
                if a[i] <= 2*a[j]:
                    i+=1
                else:
                    ans+=(m-i+1)
                    j+=1
                    
            while p <= m and q <= r:
                if a[p]==a[q]:
                    b[rr] = a[p]
                    p+=1
                    rr+=1
                elif a[p] > a[q]:
                    # ii = bisect.bisect_left(a,2*a[q],lo=l,hi=m+1)
                    # if ii!=m+1:
                    #     ans+=(m-ii+1)
                    b[rr]=a[q]
                    rr+=1
                    q+=1
                else:
                    b[rr]=a[p]
                    rr+=1
                    p+=1
            if p <= m:
                while p<=m:
                    b[rr]=a[p]
                    rr+=1
                    p+=1
            if q <= r:
                while q<=r:
                    b[rr]=a[q]
                    rr+=1
                    q+=1
            for i in range(l,r+1):
                a[i]=b[i-l]
            return ans
        
        return ms(a,l,r)
        
        