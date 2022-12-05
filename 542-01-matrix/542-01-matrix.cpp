class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int rows = v.size();
        if(!rows) return v;
        int cols = v[0].size();
        vector<vector<int>> d(rows, vector<int>(cols,INT_MAX - 1000));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(v[i][j] == 0){
                    d[i][j]=0;
                }
                else{
                    if(i > 0)
                        d[i][j] = min(d[i][j], d[i-1][j]+1);
                    if(j > 0)
                        d[i][j]=min(d[i][j],d[i][j-1]+1);
                }
            }
        }
        
        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1;j>=0;j--){
                //if(v[i][j]==1){
                    if(i+1 < rows)
                        d[i][j]=min(d[i][j], d[i+1][j]+1);
                    if(j+1 <cols)
                        d[i][j]=min(d[i][j], d[i][j+1]+1);
                //}
            }
        }
        return d;
    }
};