class Solution {
public:
    bool h(vector<vector<char>>&b,int x, int y, int i,string w){
        int m = b.size();
        int n = b[0].size();
        if( i >= w.length())
            return true;
        vector<int> d = {-1,0,1,0,-1};
        bool any = false;
        for(int p = 0; p < 4; p++){
            int nx = x+ d[p];
            int ny = y+ d[p+1];
            if(nx >= 0 and ny>=0 and nx<m and ny<n and b[nx][ny]!='#' and w[i] == b[nx][ny]){
                char c = b[nx][ny];
                b[nx][ny]='#';
                any = any or h(b,nx,ny,i+1,w);
                b[nx][ny]=c;
                if(any) break;
                
                
            }
        }
        return any;
        // return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int m, n;
        m = b.size();n=b[0].size();
        bool any = false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j <n; j++){
                if(w[0] == b[i][j]){
                    char c = b[i][j];
                    b[i][j]='#';
                    any = any or h(b,i,j,1,w);
                    b[i][j]=c;
                    if(any)
                        return true;
                }
            }
        return false;
    }
};