
typedef vector<int> vi;
typedef pair<int,int> ii;
class Solution {
public:
    bool val(int m, int n, int x, int y){
        return x>=0 and y>=0 and x <m and y <n;
    }
    vi dir = {-1,0,1,0,-1};
        
    // void dfs()
    int dfs(int i, int j,int m, int n,vector<vi>& visited, vector<vi> & image){
            visited[i][j]=1;
            int ct = 1;
            for(int r = 0; r<4; r++){
                int ip,jp;
                ip = i+ dir[r];
                jp = j+ dir[r+1];
                if( ip >= 0 and jp >=0 and ip < m and jp <n and not visited[ip][jp] and image[ip][jp]==1){
                    ct+= dfs(ip,jp,m,n,visited,image);
                }
            }
            return ct;
        }
    int maxAreaOfIsland(vector<vector<int>>& image) {
        
        
        int m,n;
        m = image.size();
        n =  image[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        // queue<ii> q;
        int mx = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(image[i][j] == 1 and not visited[i][j]){
                    mx = max(dfs(i,j,m,n,visited,image),mx);       
                }
            }
        }
        return mx == INT_MIN? 0: mx;
        
        
    }
};