class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> duplicates;
        unordered_map<int, int> seen;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            if(duplicates.insert(nums[i]).second){
                for(int j = i+1; j<n; j++){
                    int c = -nums[i]-nums[j];
                    auto it = seen.find(c);
                    if(it!=end(seen) && it->second == i){
                        vector<int> t = {nums[i], nums[j],c};
                        sort(begin(t),end(t));
                        res.insert(t);
                    }
                    seen[nums[j]]=i;
                }
            }
        return vector<vector<int>>(begin(res),end(res));
    }
};