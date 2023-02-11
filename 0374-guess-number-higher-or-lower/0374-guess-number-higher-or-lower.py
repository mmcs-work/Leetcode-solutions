# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        lo = 1
        hi = n
        while lo <= hi:
            m  = lo+(hi-lo)//2
            x =  guess(m)
            if x == -1:
                hi = m-1
            elif x == 1:
                lo = m+1
            else:
                return m
        return lo