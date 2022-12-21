class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dist(n+1,INF);
        dist[src]=0;
        for(int i = 0; i < k+1; i++){
            vector<int> temp(dist);
            for(int j = 0; j < flights.size(); j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                
                if(dist[u]!=INF)
                temp[v] =min(dist[u]+w,temp[v]);
                
                
            }
            dist=temp;
            
        }
        return dist[dst]==INF?-1: dist[dst];
    }
};