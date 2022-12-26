class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& ppp) {
        vector<vector<int>> g(n,vector<int>());
        for(auto x:ppp) g[x[1]].push_back(x[0]);
        vector<int> d(n,0);
        function<bool(int)>dfs = [&](int u){
            d[u]=1;
            for(auto v:g[u]){
                if(d[v] == 0){
                    if(dfs(v))
                        return true;
                }
                else if(d[v]==1){
                    return true;
                }
            }
            d[u]=2;
            return false;
        };
        for(int i = 0; i <n; i++){
            if(d[i]==0)
                if(dfs(i)==true)
                    return !true;
        }
        return !false;
    }
};