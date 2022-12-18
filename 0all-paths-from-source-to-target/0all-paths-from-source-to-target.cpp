typedef vector<int> vi;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        queue<vi> q;
        vi vis(n,0);
        q.push(vi({0}));
        vector<vi> ans;
        while(!q.empty()){
            vi f = q.front();
            q.pop();
            int u = f.back();
            
            if(f.back() ==(n-1) )
                ans.push_back(f);
            // if(vis[u])
            //     continue;
            for(auto v:g[u]){
                //if(!vis[v]){
                    f.push_back(v);
                    q.push(vi(f));
                    f.pop_back();
                //}
            }
            // vis[f.back()]=1;
            
        }
        return ans;
    }
};