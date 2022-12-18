typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define F first
#define S second
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        queue<iii> q;
        if(g[0][0] == 1)
            return -1;
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        q.push(iii(ii(0,0),1));
        vector<int> dir= {-1,0,1,0,-1,1,1,-1,-1};
        while(!q.empty()){
            iii x = q.front();
            q.pop();
            int xx = x.F.F;
            int y = x.F.S;
            int d = x.S;
            if(vis[xx][y]==1)
                continue;
            if( xx == (m-1) and y==(n-1))
                return d;
            for(int i = 0; i < 8; i++){
                int nx = xx + dir[i];
                int ny = y + dir[i+1];
                if(nx>=0 and ny>=0 and nx< m and ny < n and g[nx][ny]==0 and !vis[nx][ny]){
                    q.push(iii(ii(nx,ny),d+1));
                }
            }
            vis[xx][y]=1;
        }
        return -1;
    }
};