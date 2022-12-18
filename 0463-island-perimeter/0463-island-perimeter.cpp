typedef pair<int,int> ii;
class Solution {
public:
    static bool inside(int i, int j, int m, int n){
        return i>=0 and j>=0 and i<m and j<n;
    }
    int islandPerimeter(vector<vector<int>>& g) {
        int m,n;
        m =  g.size();
        n = g[0].size();
        int peri=0;
        vector<int> dir={-1,0,1,0,-1};
        // queue<pair<int,int>> q,q2;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 1){
                    for(int k = 0; k <4; k++){
                        int ni = i+dir[k];
                        int nj = j+dir[k+1];
                        if(inside(ni,nj,m,n)){
                            if(g[ni][nj] == 0)
                                peri++;
                        }
                        else{
                            peri++;
                        }
                    }
                }
                
            }
        }
        
        
        return peri;
    }
};