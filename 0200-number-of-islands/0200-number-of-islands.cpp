class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int m,n;
        m = g.size();
        n = g[0].size();
        int islands = 0;
        vector<vector<int>> v(m, vector<int>(n,0));
        for(int i = 0; i < m;  i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 0 and g[i][j] == '1'){
                    ++islands;
                    queue<pair<int,int>> q;
                    q.push(pair<int,int>(i,j));
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        int x,y;
                        x = p.first;
                        y = p.second;
                        if(!( x >=0 and y>=0 and x < m and y < n))
                        continue;
                        if(v[x][y]){
                            continue;
                        }
                        else{
                            v[x][y]=1;
                            if(g[x][y]=='1'){
                            q.push(pair<int,int>(x+1,y));

                            q.push(pair<int,int>(x-1,y));

                            q.push(pair<int,int>(x,y+1));

                            q.push(pair<int,int>(x,y-1));
                            }
                        }
                    }
                }
            }
        }
        return islands;
        
    }
};