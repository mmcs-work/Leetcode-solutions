class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i = 0; i <n; i++)
            dp[i]=1;
        for(int i = 0; i <n; i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};