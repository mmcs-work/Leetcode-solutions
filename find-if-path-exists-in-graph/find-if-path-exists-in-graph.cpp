class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> neigh(n);
        for(auto e:edges){
            neigh[e[0]].push_back(e[1]);
            neigh[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(source);
        vector<int> visited(n,0);
        while(!q.empty()){
            int u = q.front();
            visited[u]=1;
            q.pop();
            if(u == destination){
                return true;
            }
            for(auto v:neigh[u]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
        return false;
    }
};