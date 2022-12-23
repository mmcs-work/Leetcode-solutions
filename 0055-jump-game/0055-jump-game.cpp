class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> can(n,false);
        can[n-1]=true;
        int p = n-1;
        for(int i = n-2; i>=0; i--){
            if(p-i > nums[i])
                can[i] = false;
            else{
                p=i;
                can[i]=true;
            }
        }
        return can[0];
    }
};