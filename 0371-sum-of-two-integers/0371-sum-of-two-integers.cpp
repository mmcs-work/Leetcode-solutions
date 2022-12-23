class Solution {
public:
    int getSum(int a, int b) {
        // long mask = 0xFFFFFFFF;
        if(b==0) return a;
        int ans =0,carry;
        while(b){
            ans = a^b;
            carry =a&b;
            carry = ((unsigned int)carry << 1U);
            b = carry;
            a=ans;
        }
        return ans;
    }
};