class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, nn = 0;
        
        
        for (auto num : nums) {
            if (num == 0)
                nn++;
            else
                nn = 0;
            ans += nn;
        }
        
        return ans;
    }
};