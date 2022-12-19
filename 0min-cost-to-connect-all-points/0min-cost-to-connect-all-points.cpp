typedef pair<int,int> ii;
class Solution {
public:    
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 0;
        int i =0;
        int conn = 0;
        vector<bool> visited(n);
        priority_queue<ii> pq;
        while(++conn <= (n-1)){
            visited[i]=true;
            for(int j = 0; j <n; j++){
                if(!visited[j]){
                    int d = abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                    pq.push({-d,j});
                }
            }
            while(visited[pq.top().second])
                pq.pop();
            ans-=pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};