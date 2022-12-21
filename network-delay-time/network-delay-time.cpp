typedef pair<int,int> ii;
#define F first
#define S second
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<ii>> g(n+1);
        for(auto t:times)
            g[t[0]].push_back({t[1],t[2]});
        
        const int inf = 1e9;
        vector<int> dist(n+1,inf);
        vector<int> visited(n+1,0);
        dist[k]=0 ;
        priority_queue<ii, vector<ii>,greater<ii>> pq;
        
        pq.push({0,k});
        while(!pq.empty()){
            auto u = pq.top().second; pq.pop();
            if(visited[u]) continue;
            visited[u]=1;
            for(auto to:g[u]){
                auto v = to.F;
                auto w = to.S;
                if( dist[v] > (dist[u]+w)){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans== inf? -1: ans;    
    }
    
};