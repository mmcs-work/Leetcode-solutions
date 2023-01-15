class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort(reverse=True)
        ss= sum(digits)
        twos = []
        ones = []
        i = len(digits)-1
        while i >= 0 and len(twos)<2 : #and len(ones)<2:
            if digits[i]%3 == 2:
                twos.append(i)    
            i-=1
        i = len(digits)-1
        while i >= 0 and len(ones)<2 : #and len(ones)<2:
            if digits[i]%3 == 1:
                ones.append(i)    
            i-=1
        if digits[0] == 0:
            return "0"
        digits = [str(x) for x in digits]
        # ones = ones[::-1]
        # twos=twos[::-1]
        
        if (ss%3) == 0:
            return ''.join(digits)
        elif (ss%3) == 1:
            if len(ones) > 0:
                digits = digits[0:ones[0]]+digits[ones[0]+1:]
                # return ''.join(digits)
            else:
                if len(twos) > 1:
                    digits = digits[0:twos[1]]+digits[twos[1]+1:twos[0]]+digits[twos[0]+1:]
                    # return ''.join(digits)
                else:
                    return ""
        else:
            ones, twos = twos, ones
            if len(ones) > 0:
                digits = digits[0:ones[0]]+digits[ones[0]+1:]
                # return ''.join(digits)
            else:
                if len(twos) > 1:
                    digits = digits[0:twos[1]]+digits[twos[1]+1:twos[0]]+digits[twos[0]+1:]
                    # return ''.join(digits)
                else:
                    return ""
        if len(digits) > 1 and digits[0]=="0" and digits[-1]=="0":
            return "0"
        else:
            return ''.join(digits)
        # return ""