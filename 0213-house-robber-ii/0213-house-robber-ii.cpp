class Solution {
public:
    int houseRobber(vector<int>& nums) {
        // dynamic programming - decide each problem by its sub-problems:
        int before=0, beforebefore=0;
        beforebefore = nums[0];
        before = max(nums[0], nums[1]);
        int curr=0;
        for (int i=2; i<nums.size(); i++){
            curr = max(before, nums[i]+beforebefore);
            beforebefore = before;
            before=curr;
            
        }
        return before;
    }
    
    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // either use first house and can't use last or last and not first:
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};