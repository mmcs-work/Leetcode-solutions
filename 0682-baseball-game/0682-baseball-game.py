class Solution:
    def calPoints(self, operations: List[str]) -> int:
        s = []
        for c in operations:
            if c == '+' :
                a = 0
                b = 0
                if s:
                    a = s.pop()
                    if s:
                        b = s.pop()
                    s.extend([b,a,a+b])
            elif c == 'D':
                a = 0
                if s :
                    a = s[-1]
                    s.append(a+a)
            elif c =='C':
                if s:
                    s.pop()
            else:
                s.append(int(c))
        return sum(s)