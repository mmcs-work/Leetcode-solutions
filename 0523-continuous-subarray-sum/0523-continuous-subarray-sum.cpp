class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
  
        unordered_map<int, int> mp;
          for(int i=0; i<nums.size(); i++)
          {
            sum += nums[i];
            sum %= k;

            if(sum == 0 && i>0) return true;

            if(mp.find(sum) != mp.end())  
            {
              if(i - mp[sum] > 1) return true; 
            }
            else mp[sum] = i;
          }

  return false; 
        
    }
};