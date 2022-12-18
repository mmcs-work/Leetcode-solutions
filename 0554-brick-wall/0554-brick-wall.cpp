class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>m;
        int ms = INT_MIN;
        for(auto x:wall){
            int s =0;
            for(int i = 0 ; i < x.size(); i++){
                int y = x[i];
                s+=y;
                m[s]+=1;
            }
            ms = max(ms,s);
        }
        m[ms]=0;
        int ans = INT_MIN;
        for(auto x:m)
            ans = max(ans,x.second);
        return wall.size()-ans;
    }
};