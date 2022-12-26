

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int s = ans.back()[0];
            int e = ans.back()[1];
            if( not (intervals[i][1] < s or e < intervals[i][0])){
                ans.pop_back();
                ans.push_back(vector<int>{ min(intervals[i][0], s), max(intervals[i][1], e) });
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
