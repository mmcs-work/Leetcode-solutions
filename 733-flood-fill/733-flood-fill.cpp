class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m,n;
        m = image.size();
        n =  image[0].size();
        vector<vector<int>> v(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push(pair<int,int>(sr,sc));
        int mc = image[sr][sc];
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x,y;
            x = p.first;
            y = p.second;
            if(x>=0 and y>=0 and x < m and y <n){
                if(v[x][y])
                    continue;
                else{
                    v[x][y]=1;
                    if(image[x][y] == mc){
                    image[x][y]=color;
                    q.push(pair<int,int>(x+1,y));
                        q.push(pair<int,int>(x-1,y));
                        q.push(pair<int,int>(x,y+1));
                        q.push(pair<int,int>(x,y-1));
                    }
                    
                }
            }
        }
        return image;
    }
};