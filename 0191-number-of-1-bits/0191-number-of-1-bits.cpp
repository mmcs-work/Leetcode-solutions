class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a = 0;
        while(n){
            n=n&(n-1);
            a++;
        }
        return a;
    }
};