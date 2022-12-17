class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        map<double,long long> m;for(auto x: rec){
            m[(double)x[0]/x[1]]+=1;
        }
        long long ans = 0;
        for(auto x:m)
            ans+= ((long long)x.second*(x.second-1)/2);
        return ans;
    }
};